
//Axon(축색) Class
using System;
using System.Collections.Generic;

namespace Marssoft.KBrainCore
{
    public class Axon
    {
        public List<AxonTerminal> _AxonTerminals = null;
        public Dendrite _Dendrite = new Dendrite();
        public NodeofRanvier _NodeofRanvier = new NodeofRanvier();

        public Axon()
        {
            
        }
    }
}