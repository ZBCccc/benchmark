import hmac
import hashlib
import time

KEY = b"secret_key"
MESSAGE = b"Hello, World!"
ITERATIONS = 1000

start_time = time.time()

for _ in range(ITERATIONS):
    hmac.new(KEY, MESSAGE, hashlib.sha256).digest()

end_time = time.time()

print(f"Python: HMAC operation executed {ITERATIONS} times in {end_time - start_time:.6f} seconds")