# modules = a file containing python code. Separate code

import message_module as msg
from message_module import Hello, Bye # Allows to call directly the function
from message_module import * # Not a good practice, name conflict

msg.Hello()
msg.Bye()
Hello()
Bye()
help("modules")