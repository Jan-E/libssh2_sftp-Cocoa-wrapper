//
//  CK2SSHCredential.h
//  Sandvox
//
//  Created by Mike on 02/09/2011.
//  Copyright 2011 Karelia Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface NSURLCredential (CK2SSHCredential)

// Indicates that authentication should be public key, with the help of ssh-agent
// SANDBOXING: SSH-Agent isn't available to sandboxed apps, so this will fail. Apple consider SSH keys to be something user should explicitly grant access to. https://devforums.apple.com/thread/144342?tstart=0
+ (NSURLCredential *)ck2_SSHAgentCredentialWithUser:(NSString *)user;

// Authenticate using particular public & private key files
// On OS X, libssh2 generally uses the OpenSSL encryption library, so public key URL may be nil
+ (NSURLCredential *)ck2_credentialWithUser:(NSString *)user
                               publicKeyURL:(NSURL *)publicKey
                              privateKeyURL:(NSURL *)privateKey;

+ (NSURLCredential *)ck2_credentialWithUser:(NSString *)user service:(NSString *)service;

- (BOOL)ck2_isPublicKeyCredential;

// These will be nil when using ssh-agent
- (NSURL *)ck2_publicKeyURL;
- (NSURL *)ck2_privateKeyURL;

@end
