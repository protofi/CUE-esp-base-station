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
const char *ssid =     /*"HatchIT_2.4G";//*/"CueAccessPoint"; //"AarhusKommune-PSK";
const char *password =  /*"mrfunkfunk";  //*/"kummefryser";    //"Aarhus65";

// Cloud iot details.
const char *project_id = "user-test-cue-iot-cloud"; //"project-id";
const char *location = "europe-west1"; //"us-central1";
const char *registry_id = "Base-Station-Registry"; //"my-registry";
const char *device_id = "DokkX-doorbell"; //"my-esp32-device";

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
  "28:03:78:d2:d6:a3:b3:24:8e:df:42:fb:94:dd:87:"
  "58:1a:d6:06:46:6b:f8:36:51:7a:97:16:2c:9c:09:"
  "dd:12";

// Time (seconds) to expire token += 20 minutes for drift
const int jwt_exp_secs = 3600; // Maximum 24H (3600*24)

// To get the certificate for your region run:
// openssl s_client -showcerts -connect mqtt.googleapis.com:8883
// Copy the certificate (all lines between and including ---BEGIN CERTIFICATE---
// and --END CERTIFICATE--) to root.cert and put here on the root_cert variable.

const char *root_cert =
    "-----BEGIN CERTIFICATE-----\n"
    "MIIFHTCCBAWgAwIBAgIQA0lJyY6/QKQNhV+wY+0lyDANBgkqhkiG9w0BAQsFADBU"
    "MQswCQYDVQQGEwJVUzEeMBwGA1UEChMVR29vZ2xlIFRydXN0IFNlcnZpY2VzMSUw"
    "IwYDVQQDExxHb29nbGUgSW50ZXJuZXQgQXV0aG9yaXR5IEczMB4XDTE5MDMyNjEz"
    "MzMwMFoXDTE5MDYxODEzMjQwMFowbTELMAkGA1UEBhMCVVMxEzARBgNVBAgMCkNh"
    "bGlmb3JuaWExFjAUBgNVBAcMDU1vdW50YWluIFZpZXcxEzARBgNVBAoMCkdvb2ds"
    "ZSBMTEMxHDAaBgNVBAMME21xdHQuZ29vZ2xlYXBpcy5jb20wggEiMA0GCSqGSIb3"
    "DQEBAQUAA4IBDwAwggEKAoIBAQC6xYlFUBLc5F3sih2InjcUUHISzLLZYwrYEe0l"
    "oWSM26WIggrkzpxobKz4PTQFChzdNuLilDXFdxKBX7DCIbyJPkdhjrHo7ytMRtwh"
    "0YUqM7RjsvRB1fK1L9B3+GCD+IkKdrmzREcvNRqBQgOdDv2fWVDOtBkNApLGj7BY"
    "RrTe40dcxwmxAfowtgGoroPWJ387d7J0wzrmbfPY3UDOerw11IeH2z/yXyRqgaCb"
    "Z4TnLndaXiDCFjcDtgBijQH93513MQmO1Of6R/dxUcR9pN//peMwcrCu08PJrh4r"
    "X7GclHtCrANTeNqffJuD7aLRCbTN2BuhIIL5LOW8UDTWir3TAgMBAAGjggHQMIIB"
    "zDATBgNVHSUEDDAKBggrBgEFBQcDATCBpgYDVR0RBIGeMIGbghNtcXR0Lmdvb2ds"
    "ZWFwaXMuY29tghhtcXR0LW10bHMuZ29vZ2xlYXBpcy5jb22CI21xdHQtcHJlcHJv"
    "ZC5zYW5kYm94Lmdvb2dsZWFwaXMuY29tgiNtcXR0LXN0YWdpbmcuc2FuZGJveC5n"
    "b29nbGVhcGlzLmNvbYIgbXF0dC10ZXN0LnNhbmRib3guZ29vZ2xlYXBpcy5jb20w"
    "aAYIKwYBBQUHAQEEXDBaMC0GCCsGAQUFBzAChiFodHRwOi8vcGtpLmdvb2cvZ3Ny"
    "Mi9HVFNHSUFHMy5jcnQwKQYIKwYBBQUHMAGGHWh0dHA6Ly9vY3NwLnBraS5nb29n"
    "L0dUU0dJQUczMB0GA1UdDgQWBBSR6XoYreumdjvDtJW/wYfWaq5r6jAMBgNVHRMB"
    "Af8EAjAAMB8GA1UdIwQYMBaAFHfCuFCaZ3Z2sS3ChtCDoH6mfrpLMCEGA1UdIAQa"
    "MBgwDAYKKwYBBAHWeQIFAzAIBgZngQwBAgIwMQYDVR0fBCowKDAmoCSgIoYgaHR0"
    "cDovL2NybC5wa2kuZ29vZy9HVFNHSUFHMy5jcmwwDQYJKoZIhvcNAQELBQADggEB"
    "ADXLPkHVQ4Ja0IDxsaZPq35v6fqY71wQ7BzrblDQ0Q8SWIruEH/7VR77bbZJB0PF"
    "h8oYajF6rrPubQvLhdQ45CzXHolpwQBUPP0gTlesdYzWR0bqXyBm30G8rAwvxMH8"
    "7JyMJ/YslaQ1wGmphlTEM1b/Mdc4vqnCik5SAQv1HBHsLQ88osu7UZzVHg0iD1FL"
    "+Rz1QU2S0oi0PAY9yg6DaMTvtunEbD+BIcSGY36JSCl0Y1TpQwKVI4KxnFjThGcI"
    "stAKXrTvwX0ot99b8Au7fY3HZW/7V+0hS18yHDatZTE2rG/4iXWjj439DsMT79Pj"
    "+O2woV5Ck88d+73TxO0iOp0="
    "-----END CERTIFICATE-----\n";

// In case we ever need extra topics
const int ex_num_topics = 0;
const char* ex_topics[ex_num_topics];
//const int ex_num_topics = 1;
//const char* ex_topics[ex_num_topics] = {
//  "/devices/my-device/tbd/#"
//};    
