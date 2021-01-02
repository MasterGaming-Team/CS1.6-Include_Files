#if defined mg_sql_infos_included
    #endinput
#endif

#define mg_sql_infos_included

#include <amxmodx>
#include <sqlx>

stock mg_sql_info_make()
{
    static Trie:trieSqlTables

    if(Trie)
    trieSqlTables = TrieCreate()
} gSqlClassTuple = SQL_MakeDbTuple("127.0.0.1", "MG_User", "fKj4zbI0wxwPoFzU", "cs_zinsanity")