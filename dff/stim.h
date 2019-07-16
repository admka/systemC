#include "systemc.h"

SC_MODULE(stim)
{
  sc_out<bool> din;
  sc_in<bool> clk;

  void StimGen()
  {
    din.write(true);
    wait();
    din.write(false);
    wait();
    din.write(true);
    wait();
    din.write(false);
    wait();
    sc_stop();
  }
  SC_CTOR(stim)
  {
    cout << "Constructing stimulus " << name() << endl;
    SC_THREAD(StimGen);
    sensitive << clk.pos();
  }
};