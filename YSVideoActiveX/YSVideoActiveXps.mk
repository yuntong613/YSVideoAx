
YSVideoActiveXps.dll: dlldata.obj YSVideoActiveX_p.obj YSVideoActiveX_i.obj
	link /dll /out:YSVideoActiveXps.dll /def:YSVideoActiveXps.def /entry:DllMain dlldata.obj YSVideoActiveX_p.obj YSVideoActiveX_i.obj \
		kernel32.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \
.c.obj:
	cl /c /Ox /DREGISTER_PROXY_DLL \
		$<

clean:
	@del YSVideoActiveXps.dll
	@del YSVideoActiveXps.lib
	@del YSVideoActiveXps.exp
	@del dlldata.obj
	@del YSVideoActiveX_p.obj
	@del YSVideoActiveX_i.obj
