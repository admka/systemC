#include <systemc.h>
#include "mon.h"
#include "stim.h"
#include "design.cpp"



int sc_main(int sc_argc, char* sc_argv[]) {
	
  sc_signal<bool> din, dout;
  //sc_clock TestClk("TestClock", 10, SC_NS,0.5);
  sc_clock TestClk("TestClock", 10, SC_NS,0.5, 1, SC_NS);
  
  stim Stim1("Stimulus");
  Stim1.din(din);
  Stim1.clk(TestClk);

  dff DUT("myDFF");
  DUT.din(din);
  DUT.dout(dout);
  DUT.clk(TestClk);
	
  
  mon Monitor1("Monitor");
  Monitor1.din(din);
  Monitor1.dout(dout);
  Monitor1.clk(TestClk);

  

  sc_start();  // run forever
return 0;
}