/******************************************************************************
 * Copyright 2018 Google
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
// This file contains your configuration used to connect to Cloud IoT Core

// Wifi newtork details.
const char *ssid =     "HatchIT_2.4G";//*/"CueAccessPoint"; //"AarhusKommune-PSK";
const char *password =  "mrfunkfunk";  //*/"kummefryser";    //"Aarhus65";

// Cloud iot details.
const char *project_id = "hatchit-doorbell"; //"project-id";
const char *location = "europe-west1"; //"us-central1";
const char *registry_id = "Doorbell"; //"my-registry";
const char *device_id = "doorbell"; //"my-esp32-device";

// Configuration for NTP
const char* ntp_primary = "pool.ntp.org";
const char* ntp_secondary = "time.nist.gov";

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

// To get the private key run (where private-key.pem is the ec private key
// used to create the certificate uploaded to google cloud iot):
// openssl ec -in <private-key.pem> -noout -text
// and copy priv: part.
// The key length should be exactly the same as the key length bellow (32 pairs
// of hex digits). If it's bigger and it starts with "00:" delete the "00:". If
// it's smaller add "00:" to the start. If it's too big or too small something
// is probably wrong with your key.
const char *private_key_str =
  "c0:de:0e:b2:05:e0:a2:ef:0f:6e:c2:8b:70:c2:c8:"
  "be:42:85:4e:cb:cc:c7:9a:fb:0b:ca:81:b0:62:c4:"
  "0d:80";

// Time (seconds) to expire token += 20 minutes for drift
const int jwt_exp_secs = 3600; // Maximum 24H (3600*24)

// To get the certificate for your region run:
// openssl s_client -showcerts -connect mqtt.googleapis.com:8883
// Copy the certificate (all lines between and including ---BEGIN CERTIFICATE---
// and --END CERTIFICATE--) to root.cert and put here on the root_cert variable.

const char *root_cert =
    "-----BEGIN CERTIFICATE-----\n"
    "MIIFrTCCBJWgAwIBAgIQNVGc3UapumYIAAAAAA3JlDANBgkqhkiG9w0BAQsFADBC"
    "MQswCQYDVQQGEwJVUzEeMBwGA1UEChMVR29vZ2xlIFRydXN0IFNlcnZpY2VzMRMw"
    "EQYDVQQDEwpHVFMgQ0EgMU8xMB4XDTE5MDcyOTE3MjUzN1oXDTE5MTAyNzE3MjUz"
    "N1owbTELMAkGA1UEBhMCVVMxEzARBgNVBAgTCkNhbGlmb3JuaWExFjAUBgNVBAcT"
    "DU1vdW50YWluIFZpZXcxEzARBgNVBAoTCkdvb2dsZSBMTEMxHDAaBgNVBAMTE21x"
    "dHQuZ29vZ2xlYXBpcy5jb20wggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIB"
    "AQDQG9rqXOEXfee8AVBtfrrJhHsaCuCLyhmBQCfEzFH68jlSuarFGSwZuLVenc6q"
    "/avn/kqv0QjjWICNpd34vuKa51ZgPJ+naLM2PV9uaJHCGjKgudVJFsH1WwwL4w0g"
    "fY2RQ8vC2ns718kDxIg3M02KmOzi5dPDCkT821Vr5a/bBKJGwSbSJDzlox/g2wM8"
    "J+ToK8GYBsp8wVo9dRHe2zqA/gzuMdWhTU+wNCmCzlR0sOrpUQp2zo46o6Jac79b"
    "O0H6nsoQvJHOGOX+b8289u/RjSDBdjBKOfR7YnDpePnBD8T3pxITDgTLd9wKtKCe"
    "ojpjm7Edg9+MpvKSQLS+zccLAgMBAAGjggJyMIICbjAOBgNVHQ8BAf8EBAMCBaAw"
    "EwYDVR0lBAwwCgYIKwYBBQUHAwEwDAYDVR0TAQH/BAIwADAdBgNVHQ4EFgQU9Z4J"
    "SHw2KLIbyynAHUKEqY5+yKEwHwYDVR0jBBgwFoAUmNH4bhDrz5vsYJ8YkBug630J"
    "/SswZAYIKwYBBQUHAQEEWDBWMCcGCCsGAQUFBzABhhtodHRwOi8vb2NzcC5wa2ku"
    "Z29vZy9ndHMxbzEwKwYIKwYBBQUHMAKGH2h0dHA6Ly9wa2kuZ29vZy9nc3IyL0dU"
    "UzFPMS5jcnQwOAYDVR0RBDEwL4ITbXF0dC5nb29nbGVhcGlzLmNvbYIYbXF0dC1t"
    "dGxzLmdvb2dsZWFwaXMuY29tMCEGA1UdIAQaMBgwCAYGZ4EMAQICMAwGCisGAQQB"
    "1nkCBQMwLwYDVR0fBCgwJjAkoCKgIIYeaHR0cDovL2NybC5wa2kuZ29vZy9HVFMx"
    "TzEuY3JsMIIBAwYKKwYBBAHWeQIEAgSB9ASB8QDvAHUAY/Lbzeg7zCzPC3KEJ1dr"
    "M6SNYXePvXWmOLHHaFRL2I0AAAFsPvsU3QAABAMARjBEAiAYkD/lGczXvbu3izzY"
    "Fzcm7JXhYoXh5VuwGm2PMp74lAIgQtyNFCSYHGujlHXw+1y6kQyKPrHcN+PhlPn8"
    "XqvFx+sAdgB0ftqDMa0zEJEhnM4lT0Jwwr/9XkIgCMY3NXnmEHvMVgAAAWw++xTy"
    "AAAEAwBHMEUCIQC6BCoT+Awzx49j9kN6PspCvt65uXrFvM/KpVuIJ1btfwIgZUsf"
    "Z4LkBiGsDHqkbi4SgW2MqIRjPWGBaKsptNmfKdowDQYJKoZIhvcNAQELBQADggEB"
    "AAf6QbFQvhRNo1rNGyrN1ZWDTOnIWc0A3eXJRAVqooa736c2qOHeMzzTkNUpl2jk"
    "p/ZsHNseL5F+gdHHTew7xEuqNCME3UV3W9LkeR6URwpsh6TeBYrdhAimTVAWOJvX"
    "sggV+6Zf9s98vEqyH1Du84kwqBzL2FzK2ldMqCrOqvclCFmt98kG9BjLLgzYdZ2H"
    "RnsgKr1zjLXr67nKw/bf1YzTnqpme8AOT13COlgp2IdGuQHC8+PFU1pMd8yCVuvu"
    "UT9i/k5tWo6WZidPhTPGEqUpiDRpo31+PCKWoCq0opIQfXruBtQQbCj9zbVGegU/"
    "yvKl5Uoq4uN844SkJZ1nt7A="
    "-----END CERTIFICATE-----\n";

// In case we ever need extra topics
const int ex_num_topics = 0;
const char* ex_topics[ex_num_topics];
//const int ex_num_topics = 1;
//const char* ex_topics[ex_num_topics] = {
//  "/devices/my-device/tbd/#"
//};    
