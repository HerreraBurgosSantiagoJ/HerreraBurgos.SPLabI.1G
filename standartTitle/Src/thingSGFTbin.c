#include "thingSGFTBin.h"

int thing_setInitial(int startFrom)
{
    int isError=-1;
    if (!thing_isInitialSet())
    {
        FILE* newFile = fopen("../auxBin/nextID.bin","wb");
        if(newFile!=NULL)
        {
            fwrite(&nxID,sizeof(int),1,next);
            fwrite(&lastID,sizeof(int),1,next);
            fclose(next);
            isError=0;
        }
    }
    return isError;
}

int thing_next(int saving)
{
    int nxID, lastID, returner=-1;
    FILE* next = fopen("../auxBin/nextID.bin","rb");
    if(saving!=-1)
    {
        if(saving)
        {
            if (next!=NULL)
            {
                fread(&nxID,sizeof(int),1,next);
                if (nxID!=0)
                {
                    lastID=nxID-1;
                }
                returner = 0;
            }
        }
        else
        {
            if (next!=NULL)
            {
                fread(&nxID,sizeof(int),1,next);
                if (nxID!=0)
                {
                    returner=nxID;
                }
                fread(&lastID,sizeof(int),1,next);
                nxID++;
            }
        }
    }
    else
    {
        if (next!=NULL)
        {
            fread(&nxID,sizeof(int),1,next);
            fread(&lastID,sizeof(int),1,next);
            nxID=lastID+1;
        }
    }
    fclose(next);
    next = fopen("../auxBin/nextID.bin","wb");
    fwrite(&nxID,sizeof(int),1,next);
    fwrite(&lastID,sizeof(int),1,next);
    fclose(next);
    return returner;
}

int thing_isInitialSet(void);
{
    int retAux=0;
    FILE* auxFile = fopen("../auxBin/nextID.bin","rb");
    if(auxFile!=NULL)
    {
        retAux=1;
    }
    return retAux;
}
