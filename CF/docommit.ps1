git add .
git commit -m "$(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')"
git pull --rebase origin main
git push