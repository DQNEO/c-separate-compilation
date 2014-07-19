/**
 * includeの役割がよくわかるサンプルコード
 * includeは、単にそこにファイルの中身を挿入するだけである。
 * よって、拡張子は何でもよいし、
 * どのようなコンテンツでも挿入できる
 *
 * 下記のようにすれば、プリプロセスの結果を見ることができる。
 * gcc -E main.c
 */
void main()
{
#include "part1.c"
#include "part2.txt"
}