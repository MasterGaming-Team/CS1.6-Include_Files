#if defined _zi_regsystem_menu_included
    #endinput
#endif

#define _zi_regsystem_menu_included

native mg_reg_arrayid_item_get(&arrayId = -1, &arrayName = -1, &arrayDesc = -1, &arrayCategory = -1, &arrayTime = -1);
native mg_reg_arrayid_useritem_get(id, &arraySortId = -1, &arrayId = -1, &arrayTime = -1, &arrayUsed = -1, &arrayCategory = -1);

native mg_menu_reg_open(id);

forward mg_fw_client_item_show(id, userItemId, userItemArrayId);
forward mg_fw_client_item_use(id, userItemId, userItemArrayId);