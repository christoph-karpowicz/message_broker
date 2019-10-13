#include "request_pair.h"

RequestPair *RequestPair_new(const char *key, char *value)
{

    RequestPair *newRequestPair = (RequestPair *) malloc(sizeof(RequestPair));

    // Assign properties.
    newRequestPair->key = key;
    newRequestPair->value = value;
    
    // Assign methods.
    newRequestPair->getKey = &RequestPair_getKey;
    newRequestPair->getValue = &RequestPair_getValue;
    newRequestPair->destruct = &RequestPair_destruct;

    return newRequestPair;

}

const char *RequestPair_getKey(void *this)
{
    return ((RequestPair *)this)->key;
}

char *RequestPair_getValue(void *this)
{
    return ((RequestPair *)this)->value;
}

void RequestPair_destruct(void *this)
{
    free(((RequestPair *)this)->value);
    free(this);
}