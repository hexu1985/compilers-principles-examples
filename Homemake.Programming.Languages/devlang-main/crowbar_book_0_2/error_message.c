#include <string.h>
#include "crowbar.h"

MessageFormat crb_compile_error_message_format[] = {
    {"dummy"},
    {"文法エラー($(token)付近)"},
    {"不正な文字($(bad_char))"},
    {"関数名が重複しています($(name))"},
    {"dummy"},
};

MessageFormat crb_runtime_error_message_format[] = {
    {"dummy"},
    {"変数が見つかりません($(name))。"},
    {"関数が見つかりません($(name))。"},
    {"関数が要求する引数に対し、渡している引数が多すぎます。"},
    {"関数が要求する引数に対し、渡している引数が少なすぎます。"},
    {"条件式はboolean型でなければなりません。"},
    {"マイナス演算子のオペランドは数値型でなければなりません。"},
    {"2項演算子$(operator)のオペランドの型が不正です。"},
    {"$(operator)演算子はboolean型には使えません。"},
    {"fopen()関数にはファイルのパスとモード(どちらも文字列型)を"
     "渡してください。"},
    {"fclose()関数にはファイルポインタを渡してください。"},
    {"fgets()関数にはファイルポインタを渡してください。"},
    {"fputs()関数にはファイルポインタと文字列を渡してください。"},
    {"nullに対して適用できる演算は == と != だけです($(operator)はできません)。"},
    {"ゼロで除算はできません。"},
    {"グローバル変数$(name)は存在しません。"},
    {"global文は関数外では使えません。"},
    {"文字列に対し演算子$(operator)は適用できません。"},
    {"オペランドが左辺値ではありません。"},
    {"添字演算子の左オペランドが配列ではありません。"},
    {"添字演算子の中が整数ではありません。"},
    {"配列の範囲オーバーです。"
     "サイズ$(size)の配列の[$(index)]をアクセスしています。"},
    {"対象のオブジェクトには$(method_name)というメソッドはありません。"},
    {"new_array()関数には整数型(配列サイズ)を渡してください。"},
    {"インクリメント/デクリメントの対象が整数ではありません。"},
    {"配列のresize()の引数は整数型でなければなりません。"},
    {"dummy"},
};
