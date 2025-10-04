function current_branch
  echo -n (git symbolic-ref --quiet --short HEAD)
end
