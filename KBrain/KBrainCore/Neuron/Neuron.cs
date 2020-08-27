using System;
using System.Collections.Generic;

namespace Marssoft.KBrainCore.Neurons
{
    public class Neuron
    {
        public Guid _ID ;
        public NeuronType _Type;
        protected CellBody _CellBody = new CellBody();
        protected List<Axon> _Outputs = new List<Axon>();
d        protected  List<Dendrite> _Inputs = new List<Dendrite>();

        public Neuron()
        {
            _ID = new Guid();
        }  

        public void Connect(ref Neuron targetneuron)
        {

        }

        public void Disconnect(ref Neuron targetneuron)
        {

        }

        public void SendSynapse(Synapse sysnapse)
        {

        }

        public void ReveiveSynapse(Synapse sysnapse)
        {

        }
    }
}