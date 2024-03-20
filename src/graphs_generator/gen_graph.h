#ifndef GEN_GRAPH_H
#define GEN_GRAPH_H

#include "../dirs/dirs.h"

static const char* signature_names = "file_names = [ ";
static const char* signature_path  = "plt.savefig( ";

static const char* temp_script_pwd = "tmp.py";

void ScriptGraph(
    const char* result_dir,
    const char* graph_pwd ,
    const char* footage_pwd
);

#endif // !GEN_GRAPH_H