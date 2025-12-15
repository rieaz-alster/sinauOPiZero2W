What happens if you overflow an array?

Sometimes, you might get a nice, informative crash telling you it’s a stack overflow, segmentation fault, or some other error. Other times... you just get something like “Stack Smashing Detected” with zero clue where it actually happened. 😅

One way to catch these sneaky bugs is AddressSanitizer (ASan). Here’s a quick way to set it up:
- Make sure your build type is Debug
- Add the flag -fsanitize=address
- Add the flag -fno-omit-frame-pointer

With this, even those hard-to-trace stack smashes that haunt your project can finally be pinpointed. 🐛🔍