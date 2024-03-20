#include "gen_graph.h"

void ScriptGraph(
    const char* result_dir,
    const char* graph_pwd ,
    const char* footage_pwd
)
{
    assert(result_dir   != NULL);
    assert(graph_pwd    != NULL);
    assert(footage_pwd  != NULL);
    
    /*
        Initialize the directory for the future graph
    */
    DirFileInit(graph_pwd);

    /*
        Opening the file with the code template
    */
    FILE* footage = fopen(footage_pwd, "r");
    assert(footage != NULL);

    /*
        Getting the file size
    */
    fseek(footage, 0, SEEK_END);
    long footage_size = ftell(footage);
    fseek(footage, 0, SEEK_SET);

    /*
        Reading the contents of the footages
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

    /*
        I think it can be better, but so far so
    */
    FILE* python = fopen("tmp.py", "w");
    assert(python != NULL);

    /*
        We insert the first part of the program
    */
    fprintf(python, "%s", buffer);

    /*
        We insert the names of 
        the files with the results
    */
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

    /*
        We insert the following part of the program
    */
    fprintf(python, "%s", fined_names + strlen(signature_names));

    /*
        Inserting the path to save the image
    */
    fprintf(python, "'%s'", graph_pwd);
    fprintf(python, "%s", fined_path + strlen(signature_path));

    fclose(python);

    free(buffer);

    /*
        We build a graph and delete the script
    */
    static char command[PATH_MAX + 256] = {};
    sprintf(
        command,
        "python3 %s",
        temp_script_pwd
    );
    system(command);

    sprintf(
        command,
        "rm %s",
        temp_script_pwd
    );
    system(command);
}