#include "Master.h"
#include "GameSdl.h"

using namespace std;

int main(int argc, char *argv[])
{
  int pid;
  int uid;
  
//  uid=getuid();
  uid=999;
  pid=999;
  if (uid==0)
    {
      cout << "I am root, launch me as a real user" << endl;
      exit(0);
    }

  //Seeding
//  pid=getpid();
  srand(pid);
  
  game_start();
  exit(0);
}
