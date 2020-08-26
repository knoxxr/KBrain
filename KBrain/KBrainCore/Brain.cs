//Brain(뇌) class
using System;
namespace Marssoft.KBrainCore
{
    public class Brain
    {
        public FrontalLobe _FrontLobe = new FrontalLobe();
        public OccipitalLobe _OccipitalLobe = new OccipitalLobe();
        public ParientalLobe _ParientalLobe = new ParientalLobe();
        public TemporalLobe _TemporalLobe = new TemporalLobe();
        public Brain()
        {
            
        }
    }
}