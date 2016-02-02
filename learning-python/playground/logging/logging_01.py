import logging
try:
    1/0
except Exception:
    logging.exception("Deliberate divide by zero traceback", yolo="Dido")

print 23
