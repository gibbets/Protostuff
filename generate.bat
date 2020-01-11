set SRC_DIR=C:\dev\Protostuff
set DST_DIR=C:\dev\Protostuff\generated

C:\protoc-3.11.2-win64\bin\protoc -I=%SRC_DIR% --cpp_out=%DST_DIR% %SRC_DIR%\addressbook.proto