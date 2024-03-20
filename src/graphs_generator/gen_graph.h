#ifndef GEN_GRAPH_H
#define GEN_GRAPH_H

#include "../dirs/dirs.h"

static const char* signature_names = "file_names = [ ";
static const char* signature_path  = "plt.savefig( ";

void ScriptGraphCreate(
    const char* result_dir,
    const char* graph_dir ,
    const char* graph_name,
    const char* footage_dir,
    const char* footage_name
);

void ScriptGraphExecute(
    const char* graph_dir ,
    const char* graph_name
);

void ScriptGraphDelete(
    const char* graph_dir ,
    const char* graph_name
);

#endif // !GEN_GRAPH_H