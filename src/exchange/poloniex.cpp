#include <string.h>
#include <iostream>
#include <unistd.h>
#include <sstream>
#include <math.h>
#include <sys/time.h>
#include <openssl/sha.h>
#include <openssl/hmac.h>
#include "utils/base64.h"
#include <jansson.h>
#include "poloniex.h"
#include "curl_fun.h"

namespace Poloniex {

double getQuote(Parameters& params, bool isBid) {
  bool GETRequest = false;
  json_t* root = getJsonFromUrl(params, "https://poloniex.com/public?command=returnTicker", "", GETRequest);
  const char* quote;
  double quoteValue;
  if (isBid) {
    quote = json_string_value(json_object_get(json_object_get(root, "USDT_BTC"), "highestBid"));
  } else {
    quote = json_string_value(json_object_get(json_object_get(root, "USDT_BTC"), "lowestAsk"));
  }
  if (quote != NULL) {
    quoteValue = atof(quote);
  } else {
    quoteValue = 0.0;
  }
  json_decref(root);
  return quoteValue;
}

double getAvail(Parameters& params, std::string currency) {
  // TODO
}

int sendLongOrder(Parameters& params, std::string direction, double quantity, double price) {
  // TODO
}

int sendShortOrder(Parameters& params, std::string direction, double quantity, double price) {
  // TODO
}

bool isOrderComplete(Parameters& params, int orderId) {
  // TODO
}

double getActivePos(Parameters& params) {
  // TODO
}

double getLimitPrice(Parameters& params, double volume, bool isBid) {
  // TODO
}

json_t* authRequest(Parameters& params, std::string url, std::string request, std::string options) {
  // TODO
}

