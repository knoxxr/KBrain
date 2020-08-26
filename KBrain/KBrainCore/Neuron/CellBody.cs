//CellBody(세포체) Class
using System;
namespace Marssoft.KBrainCore
{
    public class CellBody
    {
        protected Nucleus _Nucleus = new Nucleus();
        public int _ActivationValue = -1;

        public CellBody()
        {
        
        }
    }
}