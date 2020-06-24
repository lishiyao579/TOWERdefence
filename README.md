# TOWERdefence——Water against Fire

### 简介：

整体类似于简单版保卫萝卜（唯一玩过的塔防式游戏…），敌人是水，火负责防御。有一条指定的路径通向终点，水怪物按路线前行，沿途设置了塔位，  
点击塔位放塔，塔攻击水怪降低血量和速度。若有一定数量水怪进入终点则游戏结束，反之则胜利。  
### 计划实现的功能：  
1.计划设计2-3关。不同关卡是同一背景（同一行进路线），有不同的初始金币值，不同的水敌人行进速度，不同的水敌人出现波数；  
2.实现三种敌人。包括，最基础类型的水敌人，2.0版水敌，3.0版水敌人；三个版本初始HP值递增，击灭得到的金币数递增；    
3.每关内出现几波敌人，后出现的敌人行进速度更快；  
4.两种火防御塔。基础类的塔可通过增加金币升级成高级塔。点击界面中的特定位置可在该位置安置塔，安置塔需要金币。  
塔可发射子弹击杀敌人,也可使敌人减速。可依靠击败水敌人获得的金币升级，升级后攻击值增加；  
5.有游戏背景音效和被击杀、升级等音效；  

### 0530已实现功能：  
背景和路线设置完成；  
塔的位置设置完成，但目前没有限制放塔位置，最终是否限制还需要测试怎样可玩性更高；  
行走路线点载入完成；  
单击左键放塔，检测是否重叠可放，绘制塔的攻击范围（便于后期测试）；  
敌人运动部分函数基本实现，存在一些调用上的问题，为保证程序可运行，此版本注释掉了走起来的部分）  
音效播放（为便于测试，目前音量设置为0）；  

### 0531改动：
1.新建GameWindow类（与上一版中的MW1类几乎完全一样，因为之前没有考虑到多个展示窗口，窗口类的命名有些混乱不便于理解，从这一版开始修改并规范）展示具体游戏；
2.新建Button类，封装按钮；
3.在GameWindow的构造函数中新建了button，做了连接；
4.在WM1的构造函数中新建了button，做了连接；
5.修改了0530版WaterEnermy的atTurnPoint函数的返回值，解决了上次存在的调用问题。（为了不影响正常运行，这段依然被注释了）


### 2020-06-11
此版本中敌人可以行走，塔可以发射子弹（还存在bug，待改），新添帮助界面，丰富了游戏界面。

##### Added
- 添加了Bullet类，封装子弹；
- 在bullet.cpp中对应添加了构造函数、nowPos函数（获取当前位置，为了利用QProperanimation进行移动）、setNowPos(功能同上)、move(控制子弹运动)、setBullet(在GameWindow中添加子弹入vector并绘制);
- 添加了IntroWindow类，封装帮助界面；
- 在introwindow.cpp中添加了构造函数（设置了按钮）、paintevent函数（绘制、画出帮助文档）、back函数（信号函数，用于回主页MW1）；
- 在GameWindow.cpp中添加了showGold、showWave函数，在游戏界面显示金币数和敌人波数；增加了removeEnemy函数（处理敌人被击中后的判断和删除）、loadWave（槽函数，游戏开始后设置敌人波数，每波敌人数并set敌人）、
  setBullet（连接到bullet的setBullet，添加并绘制子弹）
- 在GameWindow.cpp中添加UpdatMap函数（处理update的判断等）
- 在Tower.cpp中添加了计时器，shoot函数（设置子弹），lockEnemy函数（锁定某一时刻要攻击的敌人）；
- 在WaterEnemy.cpp中添加了nowPos、setNowPos函数（与bullet中类似，用于注册属性利用QProperAnimation）、beShot（处理被击中后的音效和hp减少）
- 添加了若干对应的新图片；

#### Changed
- 在Tower.cpp中把setTower设置为virtual 便于升级版塔继承；
- 在WaterEnemy.cpp的setEnemy函数中增加了hp的绘制，增加了对行进速度的控制；
- 在WaterEnemy.cpp的数据函数中做了改变，删去了turnpoint类的拐点等数据成员；
- 改变控制运动的整体思路，换用QProperAnimation；
- GameWinodw中canBuyTower函数增加了对金币的判断，金币不够不能设塔。

#### Removed
- 在WaterEnemy.cpp中删除了atTurnPoint函数（之前考虑用判断是否进入拐点控制转弯，故设置此函数。现在采用QProperAnimation控制运动，直接插入key值控制拐弯，故删除此函数，也相应地删除了本类的用于确定拐点的数据成员）；
- （换用QProperAnimation后WaterEnemy的整体数据成员中没有turnpoint类的对象了，这个类的存在有些多余，功能与Point基本重复，正在一点点做改动，准备删除turnpoint类）

此版本修复了上一版中子弹总是落后于敌人、击中后无法删除这两个bug；
此版中，游戏基本具备可玩性，子弹可打击，击中后敌人降血，hp为0时敌人死亡。固定了每轮的敌人波数，目前每轮5波。
设计了敌人产生和死亡音效。
增加了“win”之后的功能，提供下一关按钮，下一关待写。
存在的bug：敌人出生时的音乐播放时会报很多查不到的错，有时导致程序异常结束。问题不在音乐文件本身，应该与调用方式有关。待修改。

## - 2020-06-15
### Added
- 添加了BossEnemy类，作为高级版敌人，继承WaterEnemy，速度更快，血量更大；
- gamewindow.cpp中添加了eraseBullet函数（从vector移除子弹）、
winGame（游戏胜利后输出、绘制）、nextLevel（下一关）
- waterenemy.cpp中添加onSet、onErase函数，处理音效；
- bullet.cpp中添加hitTarget函数；
- 添加了若干对应的新图片、新音效；

### Changed
- gamewindow.cpp中修改了eraseEnemy函数和loadWaves函数，
把加载和控制波数的功能完全放在loadWaves中，eraseEnemy处理击中后的奖励金、从vector移除、
判断游戏是否结束（vector中没有敌人，loadWave返回bool）
- tower.cpp中修改了searchEnemy函数和lockEnemy函数；
- bullet.cpp中改变了bullet的调用方式，构造函数中加入Gamewindow*类型的对象，对应当前游戏界面；
- waterenemy.cpp中增加GameWindow*指针，改变了move函数中key值的设置，
从直接放点的坐标变为从GameWindow的turnpoints中调用；
- waterenemy.cpp中改变了beShot函数，达成减血功能；

### Removed
- 彻底删去无用的turnpoint类（用Qpoint代替了原有的功能，有些功能对应封装到其他类里）


## - 2020-06-22
- 此版本中对塔的设置方法做了改进，可以有两种塔，点击右侧塔的按钮可放对应种类的塔。计划是一个
攻击塔一个减速塔，但是减速的还没实现，不知道对于运动物体在运动中应该如何改变速度。
- 增加拆塔功能，右键点击塔位拆塔。但存在bug
pure virtual method called
terminate called without an active exception
目前查到的解决方法都不适用，正在努力修改！！
- 音乐文件换为MP3格式后可播放，但有些部分播放会导致程序卡顿，故仅在一些部分保留音效。

### Added
- Tower.cpp中增加canSlow属性，用于设置减速
- WaterEnemy.cpp中增加beSlow()，控制被减速后的操作。
- GameWindow.cpp中增加drawMenu、showMenu、setTowerType，前两者控制绘制右侧菜单栏，后者控制右键点击后选择塔的类型

### Changed
- GameWindow.cpp中改变了eraseBullet中删除bullet的方法，解决了子弹没了敌人还在自动掉血的bug
- WaterEnemy.cpp中改变了音乐格式，保证可播放
- Tower.cpp中增加了音效
- 为了修改拆塔部分还做了许多细小的改动，因为这一版提交后还会不断修改拆塔部分的bug，所以先不叙述这些改动



## - 2020-06-24
- 此版本中设置了第二种敌人BossEnemy，运行速度更快，血量更大。
- 拆塔仍然存在问题，先delete后erase会导致paintEvent里面调用画图时出问题程序异常结束，而先erase
也会报错“QObject::killTimer(): Error: timer id 375 is not valid for object 0x28c04cd0 (Bullet, ), timer has not been killed
        terminate called after throwing an instance of 'std::bad_alloc'
        what():  std::bad_alloc”
- 添加了整体的背景音乐
- 添加了放塔时的背景音乐
- （此版本主要是为了进行进一步修改bug前保存一次所以进行提交，改动很少且很集中）

### Added
- GameWindow.cpp中增加了重载的setEnemy函数和erasEnemy函数，改变了参数类型，用于放置bossEnemy类敌人
- GameWindow.cpp中把检查是否能加载下一波的代码做了封装，即添加了canLoadWave函数
- GameWindow.cpp中添加setAward函数，尝试添加award机制。
- WaterEnemy.cpp中写了析构函数，为了便于解决删除敌人时的问题。
- GameWinodw.cpp中添加了放塔时和背景音乐的播放代码

### Changed
- GameWindow.cpp中的eraseEnemy、eraseTower、eraseBullet函数都对代码顺序做了一系列改动，目的是
为了解决删除时的报错和异常结束，但现在没有找到最合适的办法。




