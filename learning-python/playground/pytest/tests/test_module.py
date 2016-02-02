# content of conftest.py
import pytest
import smtplib
from pprint import pprint



def test_ehlo(smtp):
    response, msg = smtp.ehlo()
    assert response == 250
    assert b"smtp.gmail.com" in msg
    assert 0  # for demo purposes

def test_noop(smtp):
    response, msg = smtp.noop()
    assert response == 250
    assert 0  # for demo purposes

