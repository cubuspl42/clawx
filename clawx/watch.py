import sys
import time
from shutil import copy
from watchdog.observers import Observer
from watchdog.events import PatternMatchingEventHandler

src = r"D:\data\code\github\clawx\clawx\Debug"
dest = r"D:\My Games\Clawx"

class MyHandler(PatternMatchingEventHandler):
    patterns=["*.DLL", "*.PRX"]

    def process(self, event):
        print(event.src_path, "->", dest)
        try:
            copy(event.src_path, dest)
        except Exception as e:
            print(e)

    def on_modified(self, event):
        self.process(event)

    def on_created(self, event):
        self.process(event)


if __name__ == '__main__':
    observer = Observer()
    observer.schedule(MyHandler(), path=src)
    observer.start()

    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        observer.stop()

    observer.join()