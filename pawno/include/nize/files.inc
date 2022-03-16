#include <a_samp>

stock Lini_Create(filename[])
{
	if(fexist(filename)) return 0;
	new File:file = fopen(filename, io_write);
	fclose(file);
	return 1;
}

stock Lini_WriteInt(filename[], key[], value)
{
	if(fexist(filename))
	{
	    new io;
	    new tmp[255];
		new File:file = fopen(filename, io_read);
		fread(file, tmp, 255);
		if(tmp[0])
		{
		    io = 0;
		}
		else
		{
		    io = 1;
		}
		fclose(file);
		switch(io)
		{
			case 0: file = fopen(filename, io_append);
			case 1: file = fopen(filename, io_write);
		}
		format(tmp, sizeof(tmp), "%s=%d\r\n", key, value);
		fwrite(file, tmp);
		fclose(file);
	}
	return 1;
}