extern "C" int rTrig(void *inputSignal, void *prevSignal, void *triggerVal)
{
    // check whether args all the same size
    if(sizeof(inputSignal) != sizeof(prevSignal) || sizeof(prevSignal) != sizeof(triggerVal))
    {
        return -1;
    }
    else
    {
        if( inputSignal >= prevSignal)
    }
}