#include "enums/ETimezones.hpp"

// given a ETimzones enum, return the string representation of the time e.g.
// "+03:00"
const char* getTimezoneString(ETimezones timezone) {
  if (timezone == ETimezones::MIDWAY_ISLAND) {
    return "-11:00";
  } else if (timezone == ETimezones::HAWAII) {
    return "-10:00";
  } else if (timezone == ETimezones::ALASKA) {
    return "-09:00";
  } else if (timezone == ETimezones::PACIFIC_TIME ||
             timezone == ETimezones::TIJUANA) {
    return "-08:00";
  } else if (timezone == ETimezones::ARIZONA ||
             timezone == ETimezones::MOUNTAIN_TIME) {
    return "-07:00";
  } else if (timezone == ETimezones::EL_SALVADOR ||
             timezone == ETimezones::CHIHUAHUA ||
             timezone == ETimezones::CENTRAL_TIME ||
             timezone == ETimezones::MEXICO_CITY ||
             timezone == ETimezones::SASKATCHEWAN ||
             timezone == ETimezones::TEGUCIGALPA ||
             timezone == ETimezones::SAN_JOSE ||
             timezone == ETimezones::GUATEMALA_CITY) {
    return "-06:00";
  } else if (timezone == ETimezones::BOGOTA ||
             timezone == ETimezones::EASTERN_TIME ||
             timezone == ETimezones::WASHINGTON_DC ||
             timezone == ETimezones::KINGSTON ||
             timezone == ETimezones::QUITO ||
             timezone == ETimezones::PORT_AU_PRINCE ||
             timezone == ETimezones::LIMA || timezone == ETimezones::PANAMA) {
    return "-05:00";
  } else if (timezone == ETimezones::PUERTO_RICO ||
             timezone == ETimezones::CARACAS ||
             timezone == ETimezones::ATLANTIC_TIME ||
             timezone == ETimezones::MANAUS || timezone == ETimezones::LA_PAZ ||
             timezone == ETimezones::SANTO_DOMINGO ||
             timezone == ETimezones::GUYANA) {
    return "-04:00";
  } else if (timezone == ETimezones::NEWFOUNDLAND ||
             timezone == ETimezones::SANTIAGO ||
             timezone == ETimezones::BRASILIA ||
             timezone == ETimezones::BUENOS_AIRES ||
             timezone == ETimezones::MONTEVIDEO ||
             timezone == ETimezones::ASUNCION) {
    return "-03:00";
  } else if (timezone == ETimezones::GREENLAND ||
             timezone == ETimezones::MID_ATLANTIC) {
    return "-02:00";
  } else if (timezone == ETimezones::AZORES ||
             timezone == ETimezones::CAPE_VERDE) {
    return "-01:00";
  } else if (timezone == ETimezones::BISSAU || timezone == ETimezones::BAMAKO ||
             timezone == ETimezones::ACCRA ||
             timezone == ETimezones::YAMOUSSOUKRO ||
             timezone == ETimezones::OUAGADOUGOU ||
             timezone == ETimezones::NOUAKCHOTT ||
             timezone == ETimezones::LISBON ||
             timezone == ETimezones::RABAT_CASABLANCA ||
             timezone == ETimezones::CONAKRY || timezone == ETimezones::LOME ||
             timezone == ETimezones::DAKAR ||
             timezone == ETimezones::MONROVIA ||
             timezone == ETimezones::FREETOWN ||
             timezone == ETimezones::LONDON_DUBLIN ||
             timezone == ETimezones::BANJUL) {
    return "00:00";
  } else if (timezone == ETimezones::AMSERDAM ||
             timezone == ETimezones::BELGRADE ||
             timezone == ETimezones::BRUSSELS ||
             timezone == ETimezones::SARAJEVO ||
             timezone == ETimezones::LAGOS ||
             timezone == ETimezones::DOUALA_YAOUNDE ||
             timezone == ETimezones::LIBVREVILLE ||
             timezone == ETimezones::BRAZZAVILLE ||
             timezone == ETimezones::ALGIERS ||
             timezone == ETimezones::PORTO_NOVO ||
             timezone == ETimezones::NIAMEY ||
             timezone == ETimezones::N_DJAMENA ||
             timezone == ETimezones::LUANDA || timezone == ETimezones::TUNIS ||
             timezone == ETimezones::MALABO || timezone == ETimezones::BANGUI ||
             timezone == ETimezones::MADRID || timezone == ETimezones::ROME ||
             timezone == ETimezones::BERLIN || timezone == ETimezones::PARIS ||
             timezone == ETimezones::KINSHASA ||
             timezone == ETimezones::PRAQUE || timezone == ETimezones::ZAGREB ||
             timezone == ETimezones::LJUBLJANA ||
             timezone == ETimezones::VIENNA) {
    return "+01:00";
  } else if (timezone == ETimezones::ATHENS ||
             timezone == ETimezones::BEIRUT_LEBANON ||
             timezone == ETimezones::HELSINKI ||
             timezone == ETimezones::JERUSALEM ||
             timezone == ETimezones::WINDHOEK ||
             timezone == ETimezones::LUBUMBASHI ||
             timezone == ETimezones::LUSAKA || timezone == ETimezones::HARARE ||
             timezone == ETimezones::TRIPOLI ||
             timezone == ETimezones::MAPUTO || timezone == ETimezones::KIGALI ||
             timezone == ETimezones::CAIRO ||
             timezone == ETimezones::JOHANNESBURG ||
             timezone == ETimezones::LILONGWE ||
             timezone == ETimezones::GABORONE ||
             timezone == ETimezones::BUJUMBURA ||
             timezone == ETimezones::KHARTOUM ||
             timezone == ETimezones::KILININGRAD ||
             timezone == ETimezones::JUBA || timezone == ETimezones::KYIV ||
             timezone == ETimezones::CAPE_TOWN ||
             timezone == ETimezones::SOFIA || timezone == ETimezones::NICOSIA) {
    return "+02:00";
  } else if (timezone == ETimezones::AMMAN_JORDAN ||
             timezone == ETimezones::MINSK || timezone == ETimezones::MOSCOW ||
             timezone == ETimezones::KUWAIT || timezone == ETimezones::ANKARA ||
             timezone == ETimezones::ANTANANARIVO ||
             timezone == ETimezones::DODOMA ||
             timezone == ETimezones::NAIROBI ||
             timezone == ETimezones::KAMPALA ||
             timezone == ETimezones::ADDIS_ABABA ||
             timezone == ETimezones::MOGADISHU ||
             timezone == ETimezones::RIYADH ||
             timezone == ETimezones::BAGHDAD ||
             timezone == ETimezones::DJIBOUTI ||
             timezone == ETimezones::DAMASCUS || timezone == ETimezones::DOHA ||
             timezone == ETimezones::SANAA || timezone == ETimezones::BAHRAIN ||
             timezone == ETimezones::TEHRAN) {
    return "+03:00";
  } else if (timezone == ETimezones::BAKU || timezone == ETimezones::TBILISI ||
             timezone == ETimezones::YEREVAN ||
             timezone == ETimezones::PORT_LOUIS ||
             timezone == ETimezones::ABU_DHABI ||
             timezone == ETimezones::VICTORIA ||
             timezone == ETimezones::SAMARA ||
             timezone == ETimezones::MUSSCAT) {
    return "+04:00";
  } else if (timezone == ETimezones::KABUL) {
    return "+04:30";
  } else if (timezone == ETimezones::URALSK ||
             timezone == ETimezones::YEKATERINBURG ||
             timezone == ETimezones::ASTANA ||
             timezone == ETimezones::ISLAMABAD_KARACHI ||
             timezone == ETimezones::TASHKENT) {
    return "+05:00";
  } else if (timezone == ETimezones::KOLKATA ||
             timezone == ETimezones::NEW_DELHI ||
             timezone == ETimezones::COLOMBO) {
    return "+05:30";
  } else if (timezone == ETimezones::KATHMANDU) {
    return "+05:45";
  } else if (timezone == ETimezones::DHAKA || timezone == ETimezones::OMSK ||
             timezone == ETimezones::BISHKEK) {
    return "+06:00";
  } else if (timezone == ETimezones::YANGON) {
    return "+06:30";
  } else if (timezone == ETimezones::KRASNOYARSK ||
             timezone == ETimezones::BANGKOK ||
             timezone == ETimezones::JAKARTA || timezone == ETimezones::HANOI ||
             timezone == ETimezones::PHNOM_PENH ||
             timezone == ETimezones::NOVOSSIBIRSK ||
             timezone == ETimezones::VIENTIANE ||
             timezone == ETimezones::PONTIANAK) {
    return "+07:00";
  } else if (timezone == ETimezones::IRKUTSK || timezone == ETimezones::PERTH ||
             timezone == ETimezones::TAIPEI ||
             timezone == ETimezones::KUALA_LUMPUR ||
             timezone == ETimezones::MANILA ||
             timezone == ETimezones::BEIJING ||
             timezone == ETimezones::HONG_KONG ||
             timezone == ETimezones::SINGAPORE ||
             timezone == ETimezones::BANDAR_SERI_BEGAWAN ||
             timezone == ETimezones::MAKASSAR) {
    return "+08:00";
  } else if (timezone == ETimezones::SEOUL ||
             timezone == ETimezones::TOKYO_OSAKA ||
             timezone == ETimezones::YAKUTSK || timezone == ETimezones::CHITA ||
             timezone == ETimezones::DILI || timezone == ETimezones::JAYAPURA) {
    return "+09:00";
  } else if (timezone == ETimezones::DARWIN) {
    return "+09:30";
  } else if (timezone == ETimezones::BRISBANE ||
             timezone == ETimezones::VLADIVOSTOK ||
             timezone == ETimezones::GUAM ||
             timezone == ETimezones::PORT_MORESBY) {
    return "+10:00";
  } else if (timezone == ETimezones::ADELAIDE) {
    return "+10:30";
  } else if (timezone == ETimezones::HOBART ||
             timezone == ETimezones::SYDNEY_CANBERRA ||
             timezone == ETimezones::MAGADAN ||
             timezone == ETimezones::YUZHNO_SAKHALINSK ||
             timezone == ETimezones::GUADALCANAL ||
             timezone == ETimezones::EFATE) {
    return "+11:00";
  } else if (timezone == ETimezones::MARSHALL_ISLANDS ||
             timezone == ETimezones::FIJI ||
             timezone == ETimezones::KAMCHATKA_PENINSULA ||
             timezone == ETimezones::ANADYR || timezone == ETimezones::TARAWA) {
    return "+12:00";
  } else if (timezone == ETimezones::AUCKLAND ||
             timezone == ETimezones::TONGA ||
             timezone == ETimezones::ENDERBURY ||
             timezone == ETimezones::APIA) {
    return "+13:00";
  } else if (timezone == ETimezones::KIRITIMATI) {
    return "+14:00";
  } else {
    return "00:00";
  }
}

// Return the name of that timezone e.g. "GMT +3:00"
// TODO: Later return the name of the timezone e.g. "Africa/Nairobi"
const char* getTimezoneName(ETimezones timezone) {
  if (timezone == ETimezones::MIDWAY_ISLAND) {
    return "GMT -11:00";
  } else if (timezone == ETimezones::HAWAII) {
    return "GMT -10:00";
  } else if (timezone == ETimezones::ALASKA) {
    return "GMT -09:00";
  } else if (timezone == ETimezones::PACIFIC_TIME ||
             timezone == ETimezones::TIJUANA) {
    return "GMT -08:00";
  } else if (timezone == ETimezones::ARIZONA ||
             timezone == ETimezones::MOUNTAIN_TIME) {
    return "GMT -07:00";
  } else if (timezone == ETimezones::EL_SALVADOR ||
             timezone == ETimezones::CHIHUAHUA ||
             timezone == ETimezones::CENTRAL_TIME ||
             timezone == ETimezones::MEXICO_CITY ||
             timezone == ETimezones::SASKATCHEWAN ||
             timezone == ETimezones::TEGUCIGALPA ||
             timezone == ETimezones::SAN_JOSE ||
             timezone == ETimezones::GUATEMALA_CITY) {
    return "GMT -06:00";
  } else if (timezone == ETimezones::BOGOTA ||
             timezone == ETimezones::EASTERN_TIME ||
             timezone == ETimezones::WASHINGTON_DC ||
             timezone == ETimezones::KINGSTON ||
             timezone == ETimezones::QUITO ||
             timezone == ETimezones::PORT_AU_PRINCE ||
             timezone == ETimezones::LIMA || timezone == ETimezones::PANAMA) {
    return "GMT -05:00";
  } else if (timezone == ETimezones::PUERTO_RICO ||
             timezone == ETimezones::CARACAS ||
             timezone == ETimezones::ATLANTIC_TIME ||
             timezone == ETimezones::MANAUS || timezone == ETimezones::LA_PAZ ||
             timezone == ETimezones::SANTO_DOMINGO ||
             timezone == ETimezones::GUYANA) {
    return "GMT -04:00";
  } else if (timezone == ETimezones::NEWFOUNDLAND ||
             timezone == ETimezones::SANTIAGO ||
             timezone == ETimezones::BRASILIA ||
             timezone == ETimezones::BUENOS_AIRES ||
             timezone == ETimezones::MONTEVIDEO ||
             timezone == ETimezones::ASUNCION) {
    return "GMT -03:00";
  } else if (timezone == ETimezones::GREENLAND ||
             timezone == ETimezones::MID_ATLANTIC) {
    return "GMT -02:00";
  } else if (timezone == ETimezones::AZORES ||
             timezone == ETimezones::CAPE_VERDE) {
    return "GMT -01:00";
  } else if (timezone == ETimezones::BISSAU || timezone == ETimezones::BAMAKO ||
             timezone == ETimezones::ACCRA ||
             timezone == ETimezones::YAMOUSSOUKRO ||
             timezone == ETimezones::OUAGADOUGOU ||
             timezone == ETimezones::NOUAKCHOTT ||
             timezone == ETimezones::LISBON ||
             timezone == ETimezones::RABAT_CASABLANCA ||
             timezone == ETimezones::CONAKRY || timezone == ETimezones::LOME ||
             timezone == ETimezones::DAKAR ||
             timezone == ETimezones::MONROVIA ||
             timezone == ETimezones::FREETOWN ||
             timezone == ETimezones::LONDON_DUBLIN ||
             timezone == ETimezones::BANJUL) {
    return "GMT 00:00";
  } else if (timezone == ETimezones::AMSERDAM ||
             timezone == ETimezones::BELGRADE ||
             timezone == ETimezones::BRUSSELS ||
             timezone == ETimezones::SARAJEVO ||
             timezone == ETimezones::LAGOS ||
             timezone == ETimezones::DOUALA_YAOUNDE ||
             timezone == ETimezones::LIBVREVILLE ||
             timezone == ETimezones::BRAZZAVILLE ||
             timezone == ETimezones::ALGIERS ||
             timezone == ETimezones::PORTO_NOVO ||
             timezone == ETimezones::NIAMEY ||
             timezone == ETimezones::N_DJAMENA ||
             timezone == ETimezones::LUANDA || timezone == ETimezones::TUNIS ||
             timezone == ETimezones::MALABO || timezone == ETimezones::BANGUI ||
             timezone == ETimezones::MADRID || timezone == ETimezones::ROME ||
             timezone == ETimezones::BERLIN || timezone == ETimezones::PARIS ||
             timezone == ETimezones::KINSHASA ||
             timezone == ETimezones::PRAQUE || timezone == ETimezones::ZAGREB ||
             timezone == ETimezones::LJUBLJANA ||
             timezone == ETimezones::VIENNA) {
    return "GMT +01:00";
  } else if (timezone == ETimezones::ATHENS ||
             timezone == ETimezones::BEIRUT_LEBANON ||
             timezone == ETimezones::HELSINKI ||
             timezone == ETimezones::JERUSALEM ||
             timezone == ETimezones::WINDHOEK ||
             timezone == ETimezones::LUBUMBASHI ||
             timezone == ETimezones::LUSAKA || timezone == ETimezones::HARARE ||
             timezone == ETimezones::TRIPOLI ||
             timezone == ETimezones::MAPUTO || timezone == ETimezones::KIGALI ||
             timezone == ETimezones::CAIRO ||
             timezone == ETimezones::JOHANNESBURG ||
             timezone == ETimezones::LILONGWE ||
             timezone == ETimezones::GABORONE ||
             timezone == ETimezones::BUJUMBURA ||
             timezone == ETimezones::KHARTOUM ||
             timezone == ETimezones::KILININGRAD ||
             timezone == ETimezones::JUBA || timezone == ETimezones::KYIV ||
             timezone == ETimezones::CAPE_TOWN ||
             timezone == ETimezones::SOFIA || timezone == ETimezones::NICOSIA) {
    return "GMT +02:00";
  } else if (timezone == ETimezones::AMMAN_JORDAN ||
             timezone == ETimezones::MINSK || timezone == ETimezones::MOSCOW ||
             timezone == ETimezones::KUWAIT || timezone == ETimezones::ANKARA ||
             timezone == ETimezones::ANTANANARIVO ||
             timezone == ETimezones::DODOMA ||
             timezone == ETimezones::NAIROBI ||
             timezone == ETimezones::KAMPALA ||
             timezone == ETimezones::ADDIS_ABABA ||
             timezone == ETimezones::MOGADISHU ||
             timezone == ETimezones::RIYADH ||
             timezone == ETimezones::BAGHDAD ||
             timezone == ETimezones::DJIBOUTI ||
             timezone == ETimezones::DAMASCUS || timezone == ETimezones::DOHA ||
             timezone == ETimezones::SANAA || timezone == ETimezones::BAHRAIN ||
             timezone == ETimezones::TEHRAN) {
    return "GMT +03:00";
  } else if (timezone == ETimezones::BAKU || timezone == ETimezones::TBILISI ||
             timezone == ETimezones::YEREVAN ||
             timezone == ETimezones::PORT_LOUIS ||
             timezone == ETimezones::ABU_DHABI ||
             timezone == ETimezones::VICTORIA ||
             timezone == ETimezones::SAMARA ||
             timezone == ETimezones::MUSSCAT) {
    return "GMT +04:00";
  } else if (timezone == ETimezones::KABUL) {
    return "GMT +04:30";
  } else if (timezone == ETimezones::URALSK ||
             timezone == ETimezones::YEKATERINBURG ||
             timezone == ETimezones::ASTANA ||
             timezone == ETimezones::ISLAMABAD_KARACHI ||
             timezone == ETimezones::TASHKENT) {
    return "GMT +05:00";
  } else if (timezone == ETimezones::KOLKATA ||
             timezone == ETimezones::NEW_DELHI ||
             timezone == ETimezones::COLOMBO) {
    return "GMT +05:30";
  } else if (timezone == ETimezones::KATHMANDU) {
    return "GMT +05:45";
  } else if (timezone == ETimezones::DHAKA || timezone == ETimezones::OMSK ||
             timezone == ETimezones::BISHKEK) {
    return "GMT +06:00";
  } else if (timezone == ETimezones::YANGON) {
    return "GMT +06:30";
  } else if (timezone == ETimezones::KRASNOYARSK ||
             timezone == ETimezones::BANGKOK ||
             timezone == ETimezones::JAKARTA || timezone == ETimezones::HANOI ||
             timezone == ETimezones::PHNOM_PENH ||
             timezone == ETimezones::NOVOSSIBIRSK ||
             timezone == ETimezones::VIENTIANE ||
             timezone == ETimezones::PONTIANAK) {
    return "GMT +07:00";
  } else if (timezone == ETimezones::IRKUTSK || timezone == ETimezones::PERTH ||
             timezone == ETimezones::TAIPEI ||
             timezone == ETimezones::KUALA_LUMPUR ||
             timezone == ETimezones::MANILA ||
             timezone == ETimezones::BEIJING ||
             timezone == ETimezones::HONG_KONG ||
             timezone == ETimezones::SINGAPORE ||
             timezone == ETimezones::BANDAR_SERI_BEGAWAN ||
             timezone == ETimezones::MAKASSAR) {
    return "GMT +08:00";
  } else if (timezone == ETimezones::SEOUL ||
             timezone == ETimezones::TOKYO_OSAKA ||
             timezone == ETimezones::YAKUTSK || timezone == ETimezones::CHITA ||
             timezone == ETimezones::DILI || timezone == ETimezones::JAYAPURA) {
    return "GMT +09:00";
  } else if (timezone == ETimezones::DARWIN) {
    return "GMT +09:30";
  } else if (timezone == ETimezones::BRISBANE ||
             timezone == ETimezones::VLADIVOSTOK ||
             timezone == ETimezones::GUAM ||
             timezone == ETimezones::PORT_MORESBY) {
    return "GMT +10:00";
  } else if (timezone == ETimezones::ADELAIDE) {
    return "GMT +10:30";
  } else if (timezone == ETimezones::HOBART ||
             timezone == ETimezones::SYDNEY_CANBERRA ||
             timezone == ETimezones::MAGADAN ||
             timezone == ETimezones::YUZHNO_SAKHALINSK ||
             timezone == ETimezones::GUADALCANAL ||
             timezone == ETimezones::EFATE) {
    return "GMT +11:00";
  } else if (timezone == ETimezones::MARSHALL_ISLANDS ||
             timezone == ETimezones::FIJI ||
             timezone == ETimezones::KAMCHATKA_PENINSULA ||
             timezone == ETimezones::ANADYR || timezone == ETimezones::TARAWA) {
    return "GMT +12:00";
  } else if (timezone == ETimezones::AUCKLAND ||
             timezone == ETimezones::TONGA ||
             timezone == ETimezones::ENDERBURY ||
             timezone == ETimezones::APIA) {
    return "GMT +13:00";
  } else if (timezone == ETimezones::KIRITIMATI) {
    return "GMT +14:00";
  } else {
    return "GMT 00:00";
  }
}
