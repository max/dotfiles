function envsource
    set file $argv[1]
    test -z "$file"; and set file .env
    . (sed "s/^/export /" $file | psub)
end
