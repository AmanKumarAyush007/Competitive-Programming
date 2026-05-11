@echo off
git add .
git commit -m "%date% %time%"
git pull --rebase origin main
git push