#include "systemc.h"
#include <iomanip>
#include "systemc.h"


using namespace std;


SC_MODULE(mon)
{
    sc_in<bool> din,dout;
    sc_in<bool> clk;

  void monitor()
  {
    cout << setw(10) << "Time ";
    cout << setw(2) << "din " ;
    cout << setw(2) << "dout " << endl;
    while (true)
    {
      cout << setw(10) << sc_time_stamp();
      cout << setw(2) << din.read();
      cout << setw(2) << dout.read() << endl;
      wait();    // wait for 1 clock cycle
    }
  }

  SC_CTOR(mon)
  {
    cout << "Constructing monitor " << name() << endl;
    SC_THREAD(monitor);
    sensitive << clk.pos();
  }
};