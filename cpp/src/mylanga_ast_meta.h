#ifndef MYLANGA_AST_META_H
#define MYLANGA_AST_META_H

#define field_decls(...) __field_decls_select(__VA_ARGS__, __field_decls_16, __field_decls_15, __field_decls_14, __field_decls_13, __field_decls_12, __field_decls_11, __field_decls_10, __field_decls_07, __field_decls_09, __field_decls_08, __field_decls_06, __field_decls_05, __field_decls_04, __field_decls_03, __field_decls_02, __field_decls_01)(__VA_ARGS__)
#define __field_decls_select(__01, __02, __03, __04, __05, __06, __07, __08, __09, __10, __11, __12, __13, __14, __15, __16, macro, ...) macro
#define __field_decls_01(...)
#define __field_decls_02(t,n) t n;
#define __field_decls_04(t,n,...) __field_decls_02(t,n) __field_decls_02(__VA_ARGS__)
#define __field_decls_06(t,n,...) __field_decls_02(t,n) __field_decls_04(__VA_ARGS__)
#define __field_decls_08(t,n,...) __field_decls_02(t,n) __field_decls_06(__VA_ARGS__)
#define __field_decls_10(t,n,...) __field_decls_02(t,n) __field_decls_08(__VA_ARGS__)
#define __field_decls_12(t,n,...) __field_decls_02(t,n) __field_decls_10(__VA_ARGS__)
#define __field_decls_14(t,n,...) __field_decls_02(t,n) __field_decls_12(__VA_ARGS__)
#define __field_decls_16(t,n,...) __field_decls_02(t,n) __field_decls_14(__VA_ARGS__)

#define ctor_params(...) __ctor_params_select(__VA_ARGS__, __ctor_params_16, __ctor_params_15, __ctor_params_14, __ctor_params_13, __ctor_params_12, __ctor_params_11, __ctor_params_10, __ctor_params_07, __ctor_params_09, __ctor_params_08, __ctor_params_06, __ctor_params_05, __ctor_params_04, __ctor_params_03, __ctor_params_02, __ctor_params_01)(__VA_ARGS__)
#define __ctor_params_select(__01, __02, __03, __04, __05, __06, __07, __08, __09, __10, __11, __12, __13, __14, __15, __16, macro, ...) macro
#define __ctor_params_01(...)
#define __ctor_params_02(t,n) t _##n
#define __ctor_params_04(t,n,...) __ctor_params_02(t,n), __ctor_params_02(__VA_ARGS__)
#define __ctor_params_06(t,n,...) __ctor_params_02(t,n), __ctor_params_04(__VA_ARGS__)
#define __ctor_params_08(t,n,...) __ctor_params_02(t,n), __ctor_params_06(__VA_ARGS__)
#define __ctor_params_10(t,n,...) __ctor_params_02(t,n), __ctor_params_08(__VA_ARGS__)
#define __ctor_params_12(t,n,...) __ctor_params_02(t,n), __ctor_params_10(__VA_ARGS__)
#define __ctor_params_14(t,n,...) __ctor_params_02(t,n), __ctor_params_12(__VA_ARGS__)
#define __ctor_params_16(t,n,...) __ctor_params_02(t,n), __ctor_params_14(__VA_ARGS__)

#define init_list(...) __init_list_select(__VA_ARGS__, __init_list_16, __init_list_15, __init_list_14, __init_list_13, __init_list_12, __init_list_11, __init_list_10, __init_list_07, __init_list_09, __init_list_08, __init_list_06, __init_list_05, __init_list_04, __init_list_03, __init_list_02, __init_list_01)(__VA_ARGS__)
#define __init_list_select(__01, __02, __03, __04, __05, __06, __07, __08, __09, __10, __11, __12, __13, __14, __15, __16, macro, ...) macro
#define __init_list_01(...)
#define __init_list_02(t,n) n(_##n)
#define __init_list_04(t,n,...) __init_list_02(t,n), __init_list_02(__VA_ARGS__)
#define __init_list_06(t,n,...) __init_list_02(t,n), __init_list_04(__VA_ARGS__)
#define __init_list_08(t,n,...) __init_list_02(t,n), __init_list_06(__VA_ARGS__)
#define __init_list_10(t,n,...) __init_list_02(t,n), __init_list_08(__VA_ARGS__)
#define __init_list_12(t,n,...) __init_list_02(t,n), __init_list_10(__VA_ARGS__)
#define __init_list_14(t,n,...) __init_list_02(t,n), __init_list_12(__VA_ARGS__)
#define __init_list_16(t,n,...) __init_list_02(t,n), __init_list_14(__VA_ARGS__)

#endif /* MYLANGA_AST_META_H */