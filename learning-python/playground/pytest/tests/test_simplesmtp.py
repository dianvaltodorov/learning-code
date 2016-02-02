# content of ./test_smtpsimple.py
import pytest

@pytest.fixture
def smtp():
    import smtplib
    print("dido")
    return smtplib.SMTP("smtp.gmail.com")

def test_ehlo(smtp):
    response, msg = smtp.ehlo()
    assert response == 250
    assert 0 # for demo purposes