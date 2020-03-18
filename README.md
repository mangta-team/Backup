
This program can be executed in cmd after setting system variables.

Command
work -option "path" ...

work list
- add: save string "source_path-dest_path" at dir_path/path.txt
	- have two option(root, dest)
	- ex) add -root "c:/A" -dest "d:/Backup"
- delete: delete only one string "source_path-dest_path"
	- have not option
- print: display all strings "source_path-dest_path" in dir_path/path.txt
	- have not option
- sync: file synchronization
	- have not option
- help: display help
	- have not option

option list
- root
- dest
