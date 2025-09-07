In C++, `nullptr` is a keyword introduced in C++11 that represents a null pointer, which is a pointer that does not point to any valid memory address.  
It is used to indicate that a pointer is not currently pointing to any object or function. 

`<filesystem>` – file and path operations (like os.path)  
`<fstream>` – reading/writing files  
`<sstream>` – string streams and formatting  
`<iomanip>` – time formatting, padding (e.g., std::setw)  
`<chrono>` – to get current time (system_clock)  
`<ctime>` – convert time to local/UTC (localtime)  
`<cmath>` – math functions like ceil  
`<regex>` – regular expressions (like re in Python)  
`<cstdlib>` – for environment variables, exit(), etc.  
`<pwd.h>` – to get Unix user info (like pwd in Python)  
`<grp.h>` – to get group info (like grp in Python)  
`<unistd.h>` – access POSIX system calls  
`<fnmatch.h>` – filename pattern matching (*.txt, like fnmatch)  
`<zlib.h>` – for compression (used in Git objects)  
`<openssl/sha.h>` – for SHA-1 hashing (hashlib.sha1)  
`<getopt.h>` – for command-line argument parsing (alternative to argparse)  

---

### GIT INIT

In Git, `init` does the following:  
- Creates a `.git/` directory if it doesn’t exist.  
- Initializes subdirectories like:  
  - `objects/`  
  - `refs/`  
- Writes an initial `HEAD` file pointing to `refs/heads/master`.  
- Writes a default config file.  
