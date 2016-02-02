# content of conftest.py
import pytest
import smtplib
from pprint import pprint

@pytest.fixture(scope="module",
                params=["smtp.gmail.com", "mail.python.org"])
def smtp(request):
    server = getattr(request.module, "smtpserver", "smtp.gmail.com")
    pprint(request.__dict__)
    print()
    smtp = smtplib.SMTP(server)
    yield smtp
    print ("finalizing %s (%s)" % (smtp, server))
    smtp.close()