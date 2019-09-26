(function(window,$,mw,undefined){'use strict';window.dev=window.dev||{};window.dev.i18n=window.dev.i18n||{};if(window.dev.i18n.loadMessages!==undefined){return;}var conf=mw.config.get(['debug','wgContentLanguage','wgUserLanguage']),now=Date.now(),cache={},overrides=null,fallbacks={'ab':'ru','ace':'id','aln':'sq','als':'gsw','an':'es','anp':'hi','arn':'es','arz':'ar','av':'ru','ay':'es','ba':'ru','bar':'de','bat-smg':'sgs','bcc':'fa','be-x-old':'be-tarask','bh':'bho','bjn':'id','bm':'fr','bpy':'bn','bqi':'fa','bug':'id','cbk-zam':'es','ce':'ru','ckb':'ckb-arab','crh':'crh-latn','crh-cyrl':'ru','csb':'pl','cv':'ru','de-at':'de','de-ch':'de','de-formal':'de','dsb':'de','dtp':'ms','eml':'it','ff':'fr','fiu-vro':'vro','frc':'fr','frp':'fr','frr':'de','fur':'it','gag':'tr','gan':'gan-hant','gan-hans':'zh-hans','gan-hant':'zh-hant','gl':'pt','glk':'fa','gn':'es','gsw':'de','hif':'hif-latn','hsb':'de','ht':'fr','ii':'zh-cn','inh':'ru','iu':'ike-cans','jut':'da','jv':'id','kaa':'kk-latn','kbd':
'kbd-cyrl','kbd-cyrl':'ru','khw':'ur','kiu':'tr','kk':'kk-cyrl','kk-arab':'kk-cyrl','kk-cn':'kk-arab','kk-kz':'kk-cyrl','kk-latn':'kk-cyrl','kk-tr':'kk-latn','kl':'da','koi':'ru','ko-kp':'ko','krc':'ru','ks':'ks-arab','ksh':'de','ku':'ku-latn','ku-arab':'ckb','kv':'ru','lad':'es','lb':'de','lbe':'ru','lez':'ru','li':'nl','lij':'it','liv':'et','lmo':'it','ln':'fr','ltg':'lv','lzz':'tr','mai':'hi','map-bms':'jv','mg':'fr','mhr':'ru','min':'id','mo':'ro','mrj':'ru','mwl':'pt','myv':'ru','mzn':'fa','nah':'es','nap':'it','nds':'de','nds-nl':'nl','nl-informal':'nl','no':'nb','os':'ru','pcd':'fr','pdc':'de','pdt':'de','pfl':'de','pms':'it','pt-br':'pt','qu':'es','qug':'qu','rgn':'it','rmy':'ro','rue':'uk','ruq':'ruq-latn','ruq-cyrl':'mk','ruq-latn':'ro','sa':'hi','sah':'ru','scn':'it','sg':'fr','sgs':'lt','shi':'ar','simple':'en','sli':'de','sr':'sr-ec','srn':'nl','stq':'de','su':'id','szl':'pl','tcy':'kn','tg':'tg-cyrl','tt':'tt-cyrl','tt-cyrl':'ru','ty':'fr','udm':'ru','ug':'ug-arab','uk':
'ru','vec':'it','vep':'et','vls':'nl','vmf':'de','vot':'fi','vro':'et','wa':'fr','wo':'fr','wuu':'zh-hans','xal':'ru','xmf':'ka','yi':'he','za':'zh-hans','zea':'nl','zh':'zh-hans','zh-classical':'lzh','zh-cn':'zh-hans','zh-hant':'zh-hans','zh-hk':'zh-hant','zh-min-nan':'nan','zh-mo':'zh-hk','zh-my':'zh-sg','zh-sg':'zh-hans','zh-tw':'zh-hant','zh-yue':'yue'};function getMsg(messages,name,lang,messageKey){if(conf.wgUserLanguage==='qqx'){return'(i18njs-'+messageKey+'-'+name+')';}if(overrides[messageKey]&&overrides[messageKey][name]){return overrides[messageKey][name];}if(messages[lang]&&messages[lang][name]){return messages[lang][name];}if(lang==='en'){return'<'+name+'>';}lang=fallbacks[lang]||'en';return getMsg(messages,name,lang);}function handleArgs(message,args){args.forEach(function(elem,index){var rgx=new RegExp('\\$'+(index+1),'g');message=message.replace(rgx,elem);});return message;}function makeLink(href,text,hasProtocol){text=text||href;href=hasProtocol?href:mw.util.getUrl(href)
;text=mw.html.escape(text);href=mw.html.escape(href);return'<a href="'+href+'" title="'+text+'">'+text+'</a>';}function sanitiseHtml(html){var context=document.implementation.createHTMLDocument(''),$html=$.parseHTML(html,context,false),$div=$('<div>',context).append($html),whitelistAttrs=['title','style','class'],whitelistTags=['i','b','s','br','em','strong','span',];$div.find('*').each(function(){var $this=$(this),tagname=$this.prop('tagName').toLowerCase(),attrs,array,style;if(whitelistTags.indexOf(tagname)===-1){mw.log('[I18n-js] Disallowed tag in message: '+tagname);$this.remove();return;}attrs=$this.prop('attributes');array=Array.prototype.slice.call(attrs);array.forEach(function(attr){if(whitelistAttrs.indexOf(attr.name)===-1){mw.log('[I18n-js] Disallowed attribute in message: '+attr.name+', tag: '+tagname);$this.removeAttr(attr.name);return;}if(attr.name==='style'){style=$this.attr('style');if(style.indexOf('url(')>-1){mw.log('[I18n-js] Disallowed url() in style attribute');
$this.removeAttr('style');}else if(style.indexOf('var(')>-1){mw.log('[I18n-js] Disallowed var() in style attribute');$this.removeAttr('style');}}});});return $div.prop('innerHTML');}function parse(message){var urlRgx=/\[((?:https?:)?\/\/.+?) (.+?)\]/g,simplePageRgx=/\[\[([^|]*?)\]\]/g,pageWithTextRgx=/\[\[(.+?)\|(.+?)\]\]/g,pluralRgx=/\{\{PLURAL:(\d+)\|(.+?)\}\}/gi,genderRgx=/\{\{GENDER:([^|]+)\|(.+?)\}\}/gi;if(message.indexOf('<')>-1){message=sanitiseHtml(message);}return message.replace(urlRgx,function(_match,href,text){return makeLink(href,text,true);}).replace(simplePageRgx,function(_match,href){return makeLink(href);}).replace(pageWithTextRgx,function(_match,href,text){return makeLink(href,text);}).replace(pluralRgx,function(_match,count,forms){return mw.language.convertPlural(Number(count),forms.split('|'));}).replace(genderRgx,function(_match,gender,forms){return mw.language.gender(gender,forms.split('|'));});}function markdown(message){var urlRgx=
/\[(.+?)\]\(((?:https?:)?\/\/.+?)\)/g,simplePageRgx=/\[(.+?)\]/g,pageWithTextRgx=/\[(.+?)\]\((.+?)\)/g;if(message.indexOf('<')>-1){message=sanitiseHtml(message);}return message.replace(urlRgx,function(_match,text,href){return makeLink(href,text,true);}).replace(simplePageRgx,function(_match,href){return makeLink(href);}).replace(pageWithTextRgx,function(_match,text,href){return makeLink(href,text);});}function message(messages,defaultLang,args,messageKey){if(!args.length){return;}var msgName=args.shift(),noMsg='<'+msgName+'>',msg=getMsg(messages,msgName,defaultLang,messageKey);if(args.length){msg=handleArgs(msg,args);}return{exists:msg!==noMsg,parse:function(){if(!this.exists){return this.escape();}return parse(msg);},markdown:function(){if(!this.exists){return this.escape();}return markdown(msg);},escape:function(){return mw.html.escape(msg);},plain:function(){return msg;}};}function i18n(messages,name){var defaultLang=conf.wgUserLanguage,tempLang=null,messageKey=null;if(name.indexOf(
'u:')!==0){messageKey=name;}return{useLang:function(lang){defaultLang=lang;},inLang:function(lang){tempLang=lang;return this;},useContentLang:function(){defaultLang=conf.wgContentLanguage;},inContentLang:function(){tempLang=conf.wgContentLanguage;return this;},useUserLang:function(){defaultLang=conf.wgUserLanguage;},inUserLang:function(){tempLang=conf.wgUserLanguage;return this;},msg:function(){var args=Array.prototype.slice.call(arguments),lang=defaultLang;if(tempLang!==null){lang=tempLang;tempLang=null;}return message(messages,lang,args,messageKey);},_messages:messages};}function stripComments(json){json=json.trim().replace(/\/\*[\s\S]*?\*\//g,'');return json;}function saveToCache(name,json,cacheVersion){var keyPrefix='i18n-cache-'+name;if(Object.keys(json).length===0){return;}try{localStorage.setItem(keyPrefix+'-content',JSON.stringify(json));localStorage.setItem(keyPrefix+'-timestamp',now);localStorage.setItem(keyPrefix+'-version',cacheVersion||0);}catch(e){}}function
parseMessagesToObject(name,res,cacheVersion){var json={},obj,msg;try{res=stripComments(res);json=JSON.parse(res);}catch(e){msg=e.message;if(msg==='Unexpected end of JSON input'){msg+='. This may be caused by a non-existent i18n.json page.';}console.warn('[I18n-js] SyntaxError in messages: '+msg);}obj=i18n(json,name);cache[name]=obj;if(typeof cacheVersion==='number'){saveToCache(name,json,cacheVersion);}return obj;}function loadFromCache(name,minCacheVersion){var keyPrefix='i18n-cache-'+name,twoDays=1000*60*60*24*2,cacheContent,cacheTimestamp,cacheVersion;try{cacheContent=localStorage.getItem(keyPrefix+'-content');cacheTimestamp=Number(localStorage.getItem(keyPrefix+'-timestamp'));cacheVersion=Number(localStorage.getItem(keyPrefix+'-version'));}catch(e){}if(cacheContent&&now-cacheTimestamp<twoDays&&cacheVersion>=minCacheVersion){parseMessagesToObject(name,cacheContent);}}function loadMessages(name,options){options=options||{};var deferred=$.Deferred(),useCache=(options.noCache||conf.
debug)!==!0,cacheVersion=Number(options.cacheVersion)||0,customSource=name.match(/^u:(?:([a-z-]+)\.)?([a-z0-9-]+):/),apiEndpoint='https://dev.fandom.com/api.php',page='MediaWiki:Custom-'+name+'/i18n.json',params;if(conf.wgUserLanguage==='qqx'){return deferred.resolve(i18n({},name));}if(useCache){loadFromCache(name,cacheVersion);}if(cache[name]&&useCache){return deferred.resolve(cache[name]);}if(customSource){apiEndpoint=apiEndpoint.replace('dev',customSource[2]);page=name.slice(customSource[0].length);if(customSource[1]){apiEndpoint.replace(/api\.php$/,customSource[1]+'$&');}}params={action:'query',format:'json',prop:'revisions',rvprop:'content',titles:page,indexpageids:1};mw.loader.using(['mediawiki.language','mediawiki.util'],function(){$.ajax(apiEndpoint,{data:params,dataType:'jsonp'}).always(function(data){var res='',revisionData=data.query&&data.query.pages[data.query.pageids[0]].revisions;if(revisionData){res=revisionData[0]['*'];}deferred.resolve(parseMessagesToObject(name,res
,cacheVersion));});});return deferred;}window.dev.i18n=$.extend(window.dev.i18n,{loadMessages:loadMessages,_stripComments:stripComments,_saveToCache:saveToCache,_getMsg:getMsg,_handleArgs:handleArgs,_parse:parse,_markdown:markdown,_fallbacks:fallbacks});window.dev.i18n.overrides=window.dev.i18n.overrides||{};overrides=window.dev.i18n.overrides;mw.hook('dev.i18n').fire(window.dev.i18n);}(this,jQuery,mediaWiki));;require(['mw'],function(mw){'use strict';if(window.dev&&window.dev.ui){return;}var nsAttributes={'xlink:href':'http://www.w3.org/1999/xlink'};function each(obj,cb){if(typeof obj==='object'&&typeof cb==='function'){for(var i in obj){cb(i,obj[i]);}}}function createNode(type){switch(type){case'#text':return document.createTextNode('');case undefined:case'#document-fragment':return document.createDocumentFragment();case'svg':case'use':case'g':case'path':case'circle':return document.createElementNS('http://www.w3.org/2000/svg',type);default:return document.createElement(type);}}
function appendNode(node,parent){if(parent instanceof Node){parent.appendChild(node);}else if(typeof parent==='string'){var elements=document.querySelectorAll(parent);for(var i=0;i<elements.length;i++){elements[i].appendChild(node);}}}function main(opt,parent){if(typeof opt==='string'){opt={type:'#text',text:opt};}else if(opt instanceof Node){appendNode(opt,parent);return opt;}else if(typeof opt!=='object'){throw new Error('Options parameter incorrect!');}if('condition'in opt&&!opt.condition){return;}var el=createNode(opt.type);if(typeof opt.text==='string'){el.textContent=opt.text;}if(typeof opt.html==='string'){el.innerHTML=opt.html;}each(opt.attr,function(k,v){if(typeof k==='string'){if(nsAttributes[k]){el.setAttributeNS(nsAttributes[k],k.split(':')[1],v);}else{el.setAttribute(k,v);}}});each(opt.data,function(k,v){el.setAttribute('data-'+k,v);});each(opt.style,function(k,v){el.style[k.toLowerCase().replace(/-(\w)/g,function(_,a){return a.toUpperCase();})]=v;});each(opt.events,
function(k,v){if(typeof v==='function'){el.addEventListener(k,v);}});each(opt.props,function(k,v){el[k]=v;});if(opt.classes instanceof Array){opt.classes.forEach(function(cls){el.classList.add(cls);});}if(typeof opt.checked==='boolean'){el.checked=opt.checked;}if(typeof opt.selected==='number'&&!isNaN(opt.selected)){el.selectedIndex=opt.selected;}if(typeof opt.value==='number'||typeof opt.value==='string'){el.value=String(opt.value);}if(opt.children instanceof Array){opt.children.forEach(function(c){main(c,el);});}appendNode(el,parent||opt.parent);return el;}window.dev=window.dev||{};window.dev.ui=main;mw.hook('dev.ui').fire(window.dev.ui);});;;mw.loader.state({"wikia.fake.articles.19cf434fac3269c32713caf01f3f2f42":"ready"});

/* cache key: finalfantasy:resourceloader:filter:minify-js:7:5d2bbc1a3598d54342927c0b40c7a9d4 */