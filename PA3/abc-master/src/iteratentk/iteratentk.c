#include "base/main/main.h"

ABC_NAMESPACE_IMPL_START

////////////////////////////////////////////////////////////////////////
///                        DECLARATIONS                              ///
////////////////////////////////////////////////////////////////////////

int TestC_FirstFunction(Abc_Ntk_t *pNtk);

////////////////////////////////////////////////////////////////////////
///                       FUNCTION DEFINITIONS                       ///
////////////////////////////////////////////////////////////////////////

int TestC_FirstFunctionAbc(Abc_Frame_t *pAbc)
{
    Abc_Ntk_t *pNtk;
    int result;

    // Get the read network
    pNtk = Abc_FrameReadNtk(pAbc);

    if (pNtk == NULL)
    {
        Abc_Print(ABC_ERROR, "TestCFunctionAbc: Getting the target network failed.\n");
        return 0;
    }

    //Call the main function
    result = TestC_FirstFunction(pNtk);
    
    return result;
}

int TestC_FirstFunction(Abc_Ntk_t *pNtk)
{  
    // checked if the result is strash
    if (!Abc_NtkIsStrash(pNtk))
    {
        Abc_Print(ABC_ERROR, "TestC_FirstFunction: This command is only applicable to strashed networks.\n");
        return 1;
    }

    //print information about the network
    // Abc_Print(ABC_STANDARD, "The network %s has:\n", Abc_NtkName(pNtk));
    // Abc_Print(ABC_STANDARD, "\t- %d primary inputs\n", Abc_NtkPiNum(pNtk));
    // Abc_Print(ABC_STANDARD, "\t- %d primary outputs\n", Abc_NtkPoNum(pNtk));
    // Abc_Print(ABC_STANDARD, "\t- %d nodes\n", Abc_NtkNodeNum(pNtk));
    Abc_Print(ABC_STANDARD, "<< Print Each Obj- >>\n");
    Abc_Print(ABC_STANDARD, "ID       Name Type Level\n");
    Abc_Print(ABC_STANDARD, "--------------------------------\n");
    Abc_Obj_t * pObj;

    //int sprintf(char *str, const char *format, ...);
    int i;
    Abc_NtkForEachObj(pNtk, pObj, i)
    {
        Abc_Print(ABC_STANDARD, "Id: %3d,      ", Abc_ObjId(pObj));

        char buffer[20];
        char * name = Nm_ManFindNameById(pObj->pNtk->pManName, Abc_ObjId(pObj));
        int j = snprintf(buffer, 20, "%d", Abc_ObjLevel(pObj));
        
        if (name == NULL)
        {
            char tempName[7];  // 6 characters + null terminator
            snprintf(tempName, sizeof(tempName), "n%-d", Abc_ObjId(pObj));
            Abc_Print(ABC_STANDARD, "Name: %6s, ", tempName);
        }
        else
        {
            Abc_Print(ABC_STANDARD, "Name: %6s, ", name);
        }


        Abc_Print(ABC_STANDARD, "NodeType:%3d, ", Abc_ObjType(pObj));
        Abc_Print(ABC_STANDARD, "NodeLevel:%3d, ", Abc_ObjLevel(pObj));

        Abc_Obj_t * pFanin;
        int k;

        Abc_ObjForEachFanin( pObj, pFanin, k )
        {
            Abc_Print(ABC_STANDARD, "   FiName: %6s, FaninPhase: %d ", Abc_ObjName(pFanin), Abc_ObjFaninC(pObj, k));
        }

        Abc_Print(ABC_STANDARD, "\n");
    }

    Abc_Print(ABC_STANDARD, "<< ----- End ----- >>>\n");

    return 1;
}

////////////////////////////////////////////////////////////////////////
///                       END OF FILE                                ///
////////////////////////////////////////////////////////////////////////

ABC_NAMESPACE_IMPL_END