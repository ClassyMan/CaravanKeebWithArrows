# CaravanKeebWithArrows
I got thevankeyboards/caravan but the default qmk firmware doesn't allow for arrows on the default layer so I fixed it. Learnt a lot along the way! The board is a split 44% by default but this mapping turns it into a 45%. There's an extra switch location on the PCB which just requires a bit of soldering and an extra switch to enable. 

## *Disclaimer*: 
The board is from https://thevankeyboards.com/, I am not in any way affiliated with them, just a fan.  _*I can't guarantee this won't brick your board*_, It works for me but you need to be informed about how QMK works and you need to understand that you're doing this stuff at your own risk and if you break it by not knowing what you're doing that's your responsibility. Look at the documentation on QMK for more info https://docs.qmk.fm/#/ . There's also a qmk subreddit others have found useful: https://www.reddit.com/r/olkb/ 

# Some guidance: 

In order to flash the keyboard you'll want to use the 'coding' keymap as it is the most up-to-date. However bear in mind this is slightly different to the default one. For starters enter is where it should be and so is esc, alt, o/s etc. It actually makes the board more traditional. 

Put these files in your qmk_firmware/keyboards/ folder. Putting "caravan_2_arrows_proper" directly in the keyboards folder is what makes the following commands work. _Do not put them under thevankeyboards as the following commands will then not work._

To flash use this command:

  ```qmk flash -kb caravan_2_arrows_proper -km coding```
 
To edit the layout use:
 
  ```nano keyboards/caravan_2_arrows_proper/keymaps/coding/keymap.c```
 
QMK's visual configurator does not yet/may never support this board with the arrow cluster since it's so rare, heck thevankeyboards don't even support it on their configurator. There are some extra layers above the default one, this is the bare minimum required for java development as I have discovered.  

Anyway I'm a huge fan of vankeebs and I hope you are too so if you do end up getting stuck then holla at ya boi. I basically never check github for messages though so olkb and qmk's copious documentation is a better bet. 

Good luck in all your keeby adventures. :v: :metal: :fist_raised:	

### Naming convention on releases

When I'm done tinkering around and have a relatively stable version I will release. 

The release version will be of the form \<iso-date\>-\<layout most recently updated\>
