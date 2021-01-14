* set dns
```bash
# 得到网络名称，如Wi-Fi
networksetup -listallnetworkservices
# 得到已有dns
networksetup -getdnsservers Wi-fi
# 设置dns
sudo networksetup -setdnsservers Wi-fi server1 server2
# 在已有dns基础上插入
sudo networksetup -setdnsservers Wi-fi 8.8.8.8 `networksetup -getdnsservers Wi-fi`
```

* 系统自带的可视化截图\
快捷键`Cmd+Shift+5`，可以设置保存的目录，截图后可以调用Preview编辑。点`Capture`的时候按住`control`键可以复制到剪贴板。然而没找到Preview编辑后再复制到粘贴板的操作。相比其他的截图软件还是不好用，好在可以救急。

* Rime配置
```bash
# 备份配置然后重装
mv ~/Library/Rime{,.bak}
# 安装超强音形
'/Library/Input Methods/Squirrel.app/Contents/MacOS/rime-install' pinyin-simp whjiang/cqeb
# 创建配置
cat > defaut.custom.yaml <<EOF
patch:
  schema_list:
    - {schema: cqkm} #超强快码
    - {schema: cqyx} #超强音形
    - {schema: luna_pinyin_simp} #pinyin
EOF
# 配置部分标点cqyx.schema.yaml
punctuator:
  import_preset: default
  full_shape:
    "/" : "、"
  half_shape:
    "/" : "、"
    '%' : '%'
    '*' : '*'
```

* applescript关闭钉钉数字
```applescript
on run argv
	if (count of argv) > 0 then
		set showNumber to (item 1 of argv as boolean)
	else
		set showNumber to false
	end if
	tell application "System Events"
		set activeApp to name of first application process whose frontmost is true
	end tell
	tell application "DingTalk" to activate
	
	delay 0.01
	tell application "System Events" to tell process "DingTalk"
		keystroke "," using command down
		tell window 1
			click button "通知" of toolbar 1
			set snBox to checkbox "在菜单图标上显示未读消息数"
			tell snBox
				set actual to its value as boolean
				if actual is not equal to showNumber then
					click snBox
				end if
			end tell
			# UI elements
			click button 1 of it
		end tell
	end tell
	if "DingTalk" is not in activeApp then
		tell application "System Events" to keystroke tab using command down
	end if
end run

end run
```

* brew初始化
```shell
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
# 基础类
brew install coreutils findutils gnu-tar gnu-sed gawk grep fortune neovim aria2 youtube-dl curl git asdf ctags
# App 类
brew cask install caffeine itsycal sublime-text mendeley macdown clementine appcleaner mpv kdiff3 visual-studio-code maccy squirrel openinterminal rectangle calibre go2shell cheatsheet skim xmind
# maccy 剪贴板
# 字体
brew tap homebrew/cask-fonts                  # tap 类似于 apt 中添加第三方源的 add repository 
brew cask install font-inconsolata font-fira-code font-source-code-pro
```

* brew安装指定版本
```shell
cd /usr/local/Homebrew/Library/Taps/homebrew/homebrew-core/Formula
通过git log 找到指定版本对应的.rb文件，将求保存到其他目录
brew install 保存的.rb文件
```

* 查询App标识
```shell
osascript -e 'id of app "SomeApp"'

mdls -name kMDItemCFBundleIdentifier -r SomeApp.app
```

* 编译Squirrel
```shell
1. 修改brew，允许安装boost 1.60.0
/usr/local/Homebrew/Library/Taps/homebrew/homebrew-core/Formula$ g --no-pager diff
diff --git a/Formula/boost@1.60.rb b/Formula/boost@1.60.rb
index a4c342f517..8f930a450d 100644
--- a/Formula/boost@1.60.rb
+++ b/Formula/boost@1.60.rb
@@ -17,7 +17,7 @@ class BoostAT160 < Formula

   keg_only :versioned_formula

-  disable! because: :versioned_formula
+  #disable! because: :versioned_formula

   uses_from_macos "bzip2"
   uses_from_macos "zlib"

2. 编译squirrel
https://github.com/rime/squirrel/blob/master/INSTALL.md
参考其中说明
export BOOST_ROOT=/usr/local/Cellar/boost@1.60/1.60.0/

执行完make deps后，需要修改支持的架构才能编译
diff见
https://gist.github.com/egolearner/2501b68520362d4ddc3c9b0db597736b
make package 生成pkg包
```

* markdown转pdf
```shell
brew install pandoc
brew install --cask basictex
pandoc --pdf-engine=xelatex -V CJKmainfont="Songti SC" -V colorlinks -V urlcolor=NavyBlue --toc -f markdown+smart   *.md -o result.pdf
```

* 获取ip地址
```shell
ipconfig getifaddr en0
```
