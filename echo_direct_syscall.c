#include <unistd.h>
#include <sys/syscall.h>
#include <string.h>


char buff[50];

int main()
{
        int RetVal = 0;
        for(;;)
        {
                syscall(1, 1, "Echo System > ",14);
                RetVal = syscall(0, 0, buff, 50);
                if(memcmp("exit", buff, 4) == 0)
                {
                        syscall(1, 1, "GoodBye :)\n",11);
                        break;
                }
                else
                {
                        syscall(1, 1, "You Said: ",11);
                        syscall(1, 1, buff, RetVal);
                }
        }


    return 0;
}
