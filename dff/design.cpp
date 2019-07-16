#include <systemc.h>

SC_MODULE(dff)
{
  sc_in <bool> din;
  sc_in <bool> clk;
  sc_out <bool> dout;
  
  void implement(){
  	dout = din;
  }
  
  SC_CTOR(dff){
   SC_METHOD(implement);
    sensitive_pos << clk;
    
  }
};