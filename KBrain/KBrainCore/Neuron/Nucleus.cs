//Nucleus(세포핵) Class
using System;
namespace Marssoft.KBrainCore
{
    public class Nucleus
    {
        public Nucleus()
        {
            
        }

        protected int Activation(ref int x, ref int w, ref int b)
        {
            return x*w+b;
        }

        protected double Sigmoid(ref int x)
        {
            if(x<-45) return 0;
            else if(x>45) return 1;
            else return 1/(1+Math.Exp(-x));
        }
    }
}