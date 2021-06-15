from authy.api import AuthyApiClient

# Your API key from twilio.com/console/authy/applications
# DANGER! This is insecure. See http://twil.io/secure
authy_api = AuthyApiClient('DUilwb8Q1QH45GhJ70WxwtnHKDmMHYtt')

sms = authy_api.users.request_sms(390002680)

if sms.ok():
    print(sms.content)