// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileWeapon.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Projectile.h"

void AProjectileWeapon::Fire(const FVector& HitTarget)
{
	Super::Fire(HitTarget);

	//ensuring that the weapon projectile is being fired only on the server.
	// the server controls all the important aspects
	if(!HasAuthority()) return;
	
	APawn* InstigatorPawn = Cast<APawn>(GetOwner());
	//Getting he skeletal mesh of the socket where we want to spawn the proectile.
	// We are using the muzzle flash Socket for this purpose and will be spawning the projectile in that location
	const USkeletalMeshSocket* MuzzleFlashSocket = GetWeaponMesh()->GetSocketByName(FName("MuzzleFlash"));
	
	if(MuzzleFlashSocket)
	{
		//Sockets have a built in function that return the transform (location) of that socket.
		FTransform SocketTransform = MuzzleFlashSocket->GetSocketTransform(GetWeaponMesh());

		//From muzzle flash socket to hit location from trace under crosshairs
		FVector ToTarget = HitTarget - SocketTransform.GetLocation();
		//We can always get the rotation of an FVector to get the rotation of that vector
		FRotator TargetRotation = ToTarget.Rotation();
		if(ProjectileClass && InstigatorPawn)
		{
			//why are we using a pointer here?
			UWorld* World = GetWorld();
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = GetOwner();
			SpawnParams.Instigator = InstigatorPawn;
			if(World)
			{
				World->SpawnActor<AProjectile>(
					ProjectileClass,
					SocketTransform.GetLocation(),
					TargetRotation,
					SpawnParams
				);
			}
		}
	}
}
