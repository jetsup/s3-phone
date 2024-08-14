#include <ui_utils_calculator.h>

double evaluate_expression(const char **expr, int *error);
double evaluate_term(const char **expr, int *error);
double evaluate_factor(const char **expr, int *error);

char CALC_LOG_TAG[11] = "calculator";
// Function to skip whitespaces
void skip_whitespace(const char **expr) {
  while (**expr == ' ') (*expr)++;
}

// Function to parse a number
double parse_number(const char **expr, int *error) {
  skip_whitespace(expr);
  double num = 0;
  int sign = 1;

  if (**expr == '-') {
    sign = -1;
    (*expr)++;
  }

  int has_digits = 0;
  while (isdigit(**expr) || **expr == '.') {
    has_digits = 1;
    if (**expr == '.') {
      (*expr)++;
      double decimal = 1;
      while (isdigit(**expr)) {
        decimal /= 10;
        num += decimal * (**expr - '0');
        (*expr)++;
      }
      break;
    }
    num = num * 10 + (**expr - '0');
    (*expr)++;
  }

  if (!has_digits) {
    *error = 1;
    ESP_LOGI(CALC_LOG_TAG, "Error: Expected a number but found '%c'\n", **expr);
    return 0;
  }

  skip_whitespace(expr);
  return num * sign;
}

// Function to evaluate factors (numbers or expressions inside parentheses)
double evaluate_factor(const char **expr, int *error) {
  skip_whitespace(expr);
  if (**expr == '(') {
    (*expr)++;
    double result = evaluate_expression(expr, error);
    skip_whitespace(expr);
    if (**expr == ')') {
      (*expr)++;
    } else {
      *error = 1;
      ESP_LOGI(CALC_LOG_TAG, "Error: Mismatched parentheses\n");
      return 0;
    }
    return result;
  } else {
    return parse_number(expr, error);
  }
}

// Function to evaluate terms (factors with * or /)
double evaluate_term(const char **expr, int *error) {
  double result = evaluate_factor(expr, error);
  skip_whitespace(expr);

  while (**expr == '*' || **expr == '/') {
    char op = **expr;
    (*expr)++;
    double factor = evaluate_factor(expr, error);

    if (*error) return 0;

    if (op == '*') {
      result *= factor;
    } else if (op == '/') {
      if (factor == 0) {
        *error = 1;
        ESP_LOGI(CALC_LOG_TAG, "Error: Division by zero\n");
        return 0;
      }
      result /= factor;
    }
  }
  return result;
}

// Function to evaluate the whole expression (terms with + or -)
double evaluate_expression(const char **expr, int *error) {
  double result = evaluate_term(expr, error);
  skip_whitespace(expr);

  while (**expr == '+' || **expr == '-') {
    char op = **expr;
    (*expr)++;
    double term = evaluate_term(expr, error);

    if (*error) return 0;

    if (op == '+') {
      result += term;
    } else if (op == '-') {
      result -= term;
    }
  }
  return result;
}

// Main function to evaluate the expression
double evaluate(const char *expr, int *error) {
  const char *original_expr = expr;
  double result = evaluate_expression(&expr, error);

  if (*error) {
    return 0;
  }

  skip_whitespace(&expr);

  // Check for any leftover characters
  if (*expr != '\0') {
    *error = 1;
    ESP_LOGI(CALC_LOG_TAG, "Error: Invalid character '%c' in expression\n",
             *expr);
    return 0;
  }

  // Check if the last character is a valid digit or closing parenthesis
  if (!isdigit(original_expr[strlen(original_expr) - 1]) &&
      original_expr[strlen(original_expr) - 1] != ')') {
    *error = 1;
    ESP_LOGI(CALC_LOG_TAG, "Error: Expression cannot end with '%c'\n",
             original_expr[strlen(original_expr) - 1]);
    return 0;
  }

  return result;
}

//
void remove_trailing_zeros(char *numberIn, char *numberOut) {
  int len = strlen(numberIn);
  int i, j;

  int decimal_pos = -1;
  for (i = 0; i < len; i++) {
    if (numberIn[i] == '.') {
      decimal_pos = i;
      break;
    }
  }

  if (decimal_pos == -1) {
    return;
  }

  for (i = len - 1; i > decimal_pos && numberIn[i] == '0'; i--) {
    numberIn[i] = '\0';
  }

  if (numberIn[decimal_pos] == '.' && numberIn[decimal_pos + 1] == '\0') {
    numberIn[decimal_pos] = '\0';
  }

  strcpy(numberOut, numberIn);
}
