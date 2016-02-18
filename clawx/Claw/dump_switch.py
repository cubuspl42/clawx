import os
from os import path

dump_enabled = False

while input() != "x":
	dump_enabled = not dump_enabled
	if dump_enabled:
		print("dump enabled")
		with open('dump', 'w') as file:
			pass
	else:
		print("dump disabled")
		os.remove('dump')