#include "gen_graph.h"

void ScriptGraphCreate(
    const char* result_dir,
    const char* graph_dir ,
    const char* graph_name,
    const char* footage_dir,
    const char* footage_name
)
{
    assert(result_dir   != NULL);
    assert(graph_dir    != NULL);
    assert(graph_name   != NULL);
    assert(footage_dir  != NULL);
    assert(footage_name != NULL);

    DirInit(graph_dir);

    static char footage_pwd[PATH_MAX] = {};
    sprintf(
        footage_pwd,
        "%s/%s",
        footage_dir,
        footage_name
    );

    FILE* footage = fopen(footage_pwd, "r");
    assert(footage != NULL);

    /*Getting the file size*/
    fseek(footage, 0, SEEK_END);
    long footage_size = ftell(footage);
    fseek(footage, 0, SEEK_SET);

    /*
        Add 1 for the ending character i.e. '\0'
    */
    char* buffer = calloc(footage_size + 1, sizeof(char));
    assert(buffer != NULL);
    size_t fread_status = fread(
        buffer      ,
        sizeof(char), 
        footage_size, 
        footage
    );
    assert(fread_status == footage_size * sizeof(char));
    fclose(footage);

    char* fined_names = strstr(buffer, signature_names);
    char* fined_path  = strstr(buffer, signature_path );

    fined_names[strlen(signature_names) - 1] = '\0';
    fined_path [strlen(signature_path ) - 1] = '\0';

    static char graph_pwd[PATH_MAX] = {};

    sprintf(
        graph_pwd   ,
        "%s/%s"     ,
        graph_dir   ,
        graph_name
    );

    FILE* python = fopen("tmp.py", "w");
    assert(python != NULL);

    fprintf(python, "%s", buffer);

    Dir* dir = DirCtor(result_dir);
    char* test_name = NULL;
    if((test_name = DirGetNextFileName(dir)) != NULL)
    {
        fprintf(python, "'%s'", test_name);
    }
    while((test_name = DirGetNextFileName(dir)) != NULL)
    {
        fprintf(python, ", '%s'", test_name);
    }
    DirDtor(dir);

    fprintf(python, "%s", fined_names + strlen(signature_names));
    fprintf(python, "'%s'", graph_pwd);
    fprintf(python, "%s", fined_path + strlen(signature_path));

    fclose(python);

    free(buffer);
}
