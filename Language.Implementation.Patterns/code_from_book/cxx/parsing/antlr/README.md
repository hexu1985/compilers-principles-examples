
### 手动安装antlr4
```bash
# 安装 Java（如果尚未安装）
$ sudo apt install openjdk-17-jre
# 下载 ANTLR4 工具 jar
$ curl -O https://www.antlr.org/download/antlr-4.13.0-complete.jar
$ sudo mv antlr-4.13.0-complete.jar /usr/local/lib
$ echo 'alias antlr4="java -jar /usr/local/lib/antlr-4.13.0-complete.jar"' >> ~/.bashrc
# source ~/.bashrc
```

### 编译并安装匹配版本的 C++ 运行时库
```bash
# 下载源码（版本号必须与 jar 一致）
$ git clone https://github.com/antlr/antlr4.git
$ cd antlr4
$ git checkout 4.13.0
$ cd runtime/Cpp

# 编译
$ cmake -S. -Bbuild
$ cmake --build build

# 安装
$ cmake --install build --prefix ~/local/antlr4
```
