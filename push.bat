@echo off
git init

git config user.name "RainPPR"
git config user.email "ppr2125773894@163.com"

git add .
git commit -m "commit"
git branch -M main
git remote add origin https://gitee.com/RainPPR/my-oi.git
git push -u origin main
pause