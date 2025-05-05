#include "base/main/main.h"
#include "iteratentk.h"

ABC_NAMESPACE_HEADER_START

////////////////////////////////////////////////////////////////////////
///                        DECLARATIONS                              ///
////////////////////////////////////////////////////////////////////////

static int TestC_CommandTestC(Abc_Frame_t *pAbc, int argc, char **argv);

////////////////////////////////////////////////////////////////////////
///                     FUNCTION DEFINITIONS                         ///
////////////////////////////////////////////////////////////////////////

void TestC_Init(Abc_Frame_t *pAbc)
{
    Cmd_CommandAdd(pAbc, "Various", "iteratentk", TestC_CommandTestC, 0);
}

int TestC_CommandTestC(Abc_Frame_t *pAbc, int argc, char **argv)
{
    int fVerbose;
    int c, result;
    fVerbose = 0;
    Extra_UtilGetoptReset();
    while ((c = Extra_UtilGetopt(argc, argv, "wh")) != EOF)
    {
        switch (c)
        {
        case 'v':
            fVerbose ^= 1;
            break;
        case 'h':
            goto usage;
        default:
            goto usage;
        }
    }

    result = TestC_FirstFunctionAbc(pAbc);

    if (fVerbose)
    {
        Abc_Print(ABC_STANDARD, "\nVerbose mode is on.\n");
        if(result)
        {
            Abc_Print(ABC_STANDARD, "The command dinished successfully.\n");
        }
        else
        {
            Abc_Print(ABC_STANDARD, "The conmmand execution has failed.\n");
        }
    }
    return 0;

    usage:
        Abc_Print(-2, "usage: firstcmd [-vh]\n");
        Abc_Print(-2, "\t First command in ABC\n");
        Abc_Print(-2, "\t-v    : toggle printing verbose information [default = %s]\n", fVerbose ? "yes" : "no");
        Abc_Print(-2, "\t-h    : print the command usage\n");
        return 1;
}